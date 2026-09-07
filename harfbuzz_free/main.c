#include "./include/harfbuzz.h"
// first create the whole objects 
Font font;
hb_rsrs hb_rs;
glyph_infos glyph_info;

int main () {

    char* pathname="/usr/share/fonts/truetype/ubuntu/Ubuntu-C.ttf";

     free_type_init (&font,pathname,48);
    // create resources 
    create_resources (&font,&hb_rs);
    create_shaping   (&hb_rs ,"we are here ",&font);
    get_glyph_info   (& glyph_info,&hb_rs,&font);



}

