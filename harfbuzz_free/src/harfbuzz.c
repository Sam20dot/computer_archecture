#include "../include/harfbuzz.h"
#include "freetype/freetype.h"


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
    bitmap.rows                  =glyph_info->height;
    bitmap.width                 =glyph_info->width;
    font->face->glyph->bitmap_top =glyph_info->left_offset;
    font->face->glyph->bitmap_top=glyph_info->top_offset;

     printf ("\n the glp data position infos \n");
     printf ("\n the glyph id is :%u\n",glyph_info[i].glyphId);


     printf ("\n the x advance :%f\n",glyph_info[i].x_advance);
     printf ("\n the y advance :%f\n",glyph_info[i].y_advance);
     printf ("\n the x offset  :%d\n",glyph_info[i].x_offset);
     printf ("\n the y offset  :%d\n",glyph_info[i].y_offset);
 



   }
    return 1;

}






