#include "./include/harfbuzz.h"
// first create the whole objects 
Font font;
hb_rsrs hb_rs;
glyph_infos glyph_info[MAX_UNIQUE_GLYPHS];
atlasTextureRegion cache [MAX_UNIQUE_GLYPHS];
TextureAtlas atlas;



int main () {

    char* pathname="/usr/share/fonts/truetype/ubuntu/Ubuntu-C.ttf";

     free_type_init (&font,pathname,64);
    // create resources 
    create_resources (&font,&hb_rs);
    create_shaping   (&hb_rs ,"we are here ",&font);
    get_glyph_info   ( glyph_info,&hb_rs,&font);
    atlas_init (&atlas);
    printf ("\n atlas initilzed !!\n");

    for (int i = 0; i < 12; i++) { // Swap 12 with your actual string character count
    
    // FIX A: Pass glyph_info[i] so it moves down the array of letters!
    atlasTextureRegion *atlas_cache = atlas_get_or_pack(&atlas, &font, glyph_info[i].glyphId);

    if (atlas_cache != NULL) {
        printf("\n--- Character Index %d (Glyph ID: %u) ---\n", i, atlas_cache->glyphId);
        
        // FIX B: Use -> instead of [i] to read directly from the returned slot pointer!
        printf("the uv cordinates are u0 :%f u1:%f\n", atlas_cache->u0, atlas_cache->u1);
        printf("the uv cordinates are v0 :%f v1:%f\n", atlas_cache->v0, atlas_cache->v1);
    }
}
     




}

