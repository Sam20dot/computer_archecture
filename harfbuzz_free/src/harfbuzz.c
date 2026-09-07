#include "../include/harfbuzz.h"
#include "freetype/freetype.h"
#define     ATLAS_WIDTH      512
#define     ATLAS_HEIGHT     512
#define     MAX_UNIQUE_GLYPHS 256




int create_resources (Font *font, hb_rsrs *hb_rs) {
    hb_rs->hb_fonts=hb_ft_font_create_referenced (font->face);
    hb_rs->hb_buffer=hb_buffer_create ();

    return 1;   
}
int create_shaping (hb_rsrs *hb_rs, char *text,Font*font) {
   

    // first we set the character pixel size 
    hb_buffer_add_utf8        (hb_rs->hb_buffer,text,-1,0,-1);
    hb_buffer_set_direction   (hb_rs->hb_buffer,HB_DIRECTION_LTR);
    hb_buffer_set_script      (hb_rs->hb_buffer,HB_SCRIPT_LATIN); 
    hb_buffer_set_language    (hb_rs->hb_buffer,hb_language_from_string ("en",-1));
    hb_shape                  (hb_rs->hb_fonts,hb_rs->hb_buffer,NULL,0);
    return 1;


}


void atlas_init      (TextureAtlas *atlas) {

    memset (atlas->pixels,0,sizeof (atlas->pixels));
    // starting the cursor at 2 and other part 
    atlas->cursor_x=2;
    atlas->cursor_y=2;
    atlas->row_max_height=0;
    // then put all cached as force values 
    for (int i=0; i<MAX_UNIQUE_GLYPHS; i++) {

        atlas->cache[i].is_cached=false;


    }

}
// 1. Initialize your atlas memory on the CPU
// 2. The core allocator: Finds a cached character or asks FreeType to render it

atlasTextureRegion * atlas_get_or_pack (TextureAtlas *atlas,Font*font,hb_codepoint_t glyphId) {
    
    // --- LOOKUP STEP ---
    // Scan your 256 parking spots to see if this glyph was already drawn before
    for (int i = 0; i < MAX_UNIQUE_GLYPHS; i++) {
        if (atlas->cache[i].is_cached && atlas->cache[i].glyphId == glyphId) {
            return &atlas->cache[i]; // Instant hit! Return existing UV fractions
        }
    }

    // --- ALLOCATION STEP ---
    // If it's a new glyph, find the first open slot in our tracking array
    int slot = -1;
    for (int i = 0; i < MAX_UNIQUE_GLYPHS; i++) {
        if (!atlas->cache[i].is_cached) {
            slot = i;
            break;
        }
    }
    
    // Safety check: if you fill all slots, wipe and reset the canvas
    if (slot == -1) {
        printf("Warning: PLab Glyph Cache limit reached! Resetting atlas...\n");
        atlas_init(atlas);
        slot = 0; 
    }

    // --- RENDER STEP ---
    // Ask your FreeType core to extract the vector geometry for this specific ID
    if (FT_Load_Glyph(font->face, glyphId, FT_LOAD_DEFAULT) != FT_Err_Ok) return NULL;
    if (FT_Render_Glyph(font->face->glyph, FT_RENDER_MODE_NORMAL) != FT_Err_Ok) return NULL;

    FT_Bitmap *bitmap = &font->face->glyph->bitmap;

    // Handle space character cleanly so it doesn't take up texture space
    if (bitmap->width == 0 || bitmap->rows == 0) {
        atlas->cache[slot].glyphId = glyphId;
        atlas->cache[slot].u0 = atlas->cache[slot].v0 = 0.0f;
        atlas->cache[slot].u1 = atlas->cache[slot].v1 = 0.0f;
        atlas->cache[slot].is_cached = true;
        return &atlas->cache[slot];
    }

    // --- ROW WRAPPING MATH ---
    // Check if drawing this character pushes us past the 512px right border
    if (atlas->cursor_x + (int)bitmap->width + 2 >=ATLAS_WITDH) {
        atlas->cursor_x = 2; // Carriage return back to the left wall
        atlas->cursor_y += atlas->row_max_height + 4; // Jump down past last row's tallest letter
        atlas->row_max_height = 0; // Reset tracking height for the new row
    }

    // Check if the font allocation runs completely off the bottom of the 512px box
    if (atlas->cursor_y + (int)bitmap->rows + 2 >= ATLAS_HEIGHT) {
        printf("Error: 512x512 Texture Atlas is completely full!\n");
        return NULL;
    }

    // --- BITMAP MEMORY BLIT (COPY) ---
    // Copy the raw 8-bit grayscale pixels out of FreeType's buffer into our master image grid
    for (int row = 0; row < (int)bitmap->rows; row++) {
        for (int col = 0; col < (int)bitmap->width; col++) {
            int src_idx = row * bitmap->pitch + col;
            int dst_idx = (atlas->cursor_y + row) * ATLAS_WIDTH + (atlas->cursor_x + col);
            atlas->pixels[dst_idx] =(unsigned char)bitmap->buffer[src_idx];

        }
    }

    // --- FRACTIONAL UV PERCENTAGE CALCULATION ---
    // Maps the exact pixel bounds into an optimized 0.0 to 1.0 floating range for your shaders
    atlas->cache[slot].glyphId = glyphId;
    atlas->cache[slot].u0 = (float)atlas->cursor_x / (float)ATLAS_WIDTH;
    atlas->cache[slot].v0 = (float)atlas->cursor_y / (float)ATLAS_HEIGHT;
    atlas->cache[slot].u1 = (float)(atlas->cursor_x + bitmap->width) / (float)ATLAS_WIDTH;
    atlas->cache[slot].v1 = (float)(atlas->cursor_y + bitmap->rows) / (float)ATLAS_HEIGHT;
    atlas->cache[slot].is_cached = true;

    // --- CURSOR ADVANCE ---
    // Move the packing pointer forward to prepare for the next letter, leaving 4px padding
    atlas->cursor_x += (int)bitmap->width + 4;
    if ((int)bitmap->rows > atlas->row_max_height) {
        atlas->row_max_height = (int)bitmap->rows;
    }

    return &atlas->cache[slot];
}


int get_glyph_info (glyph_infos * glyph_info,hb_rsrs *hb_rs,Font*font) {

    unsigned int glyph_counts;
    hb_rs->glyph_info=hb_buffer_get_glyph_infos     (hb_rs->hb_buffer,&glyph_counts);
    hb_rs->glyph_pos =hb_buffer_get_glyph_positions (hb_rs->hb_buffer,&glyph_counts);
   // then pack all data within that glyph info structure 
   for (int i=0;i<glyph_counts;i++) {

       glyph_info[i].glyphId  = hb_rs->glyph_info[i].codepoint;
       glyph_info[i].x_advance= hb_rs->glyph_pos[i].x_advance/64.0;
       glyph_info[i].y_advance= hb_rs->glyph_pos[i].y_advance/64.0;
       glyph_info[i].x_offset = hb_rs->glyph_pos[i].x_offset;
       glyph_info[i].y_offset = hb_rs->glyph_pos[i].y_offset;
     if (FT_Load_Glyph(font->face, glyph_info[i].glyphId,FT_LOAD_DEFAULT)==FT_Err_Ok) {

        printf ("\n the character loaded \n");
    }
    if (FT_Render_Glyph(font->face->glyph,FT_RENDER_MODE_NORMAL)==FT_Err_Ok) {

        printf ("\n the glyph has been rendered \n");

    }
    FT_Bitmap bitmap=font->face->glyph->bitmap;
   glyph_info[i].height= bitmap.rows;
   glyph_info[i].width  =  bitmap.width;
   glyph_info[i].left_offset=font->face->glyph->bitmap_left;
   glyph_info[i].top_offset =font->face->glyph->bitmap_top;

     printf ("\n the glp data position infos \n");
     printf ("\n the glyph id is :%u\n",glyph_info[i].glyphId);


     printf ("\n the x advance :%f\n",glyph_info[i].x_advance);
     printf ("\n the y advance :%f\n",glyph_info[i].y_advance);
     printf ("\n the x offset  :%d\n",glyph_info[i].x_offset);
     printf ("\n the y offset  :%d\n",glyph_info[i].y_offset);
     printf(" \n Bitmap dimensions: %d x %d pixels\n",glyph_info[i].width, glyph_info[i].height);
     printf(" \nTop offset: %d px, Left offset: %d px\n",glyph_info[i].top_offset,glyph_info[i].left_offset);

   
    



 
 



   }
    return 1;

}

