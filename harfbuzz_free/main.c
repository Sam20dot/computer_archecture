#include "./include/harfbuzz.h"
// first create the whole objects 
Font font;
hb_rsrs hb_rs;
glyph_infos glyph_info;
atlasTextureRegion cache [MAX_UNIQUE_GLYPHS];
TextureAtlas atlas;



int main () {

    char* pathname="/usr/share/fonts/truetype/ubuntu/Ubuntu-C.ttf";

     free_type_init (&font,pathname,48);
    // create resources 
    create_resources (&font,&hb_rs);
    create_shaping   (&hb_rs ,"we are here ",&font);
    get_glyph_info   (& glyph_info,&hb_rs,&font);
    atlas_init (&atlas);
    printf ("\n atlas initilzed !!\n");
      atlasTextureRegion *atlas_cache=atlas_get_or_pack (&atlas,&font,glyph_info.glyphId);
     printf ("the uv cordinates are u0 :%f u1:%f\n",atlas_cache->u0,atlas_cache->u1);
    printf ("the uv cordinates are u0 :%f u1:%f\n",atlas_cache->v0,atlas_cache->v1);



     




}

