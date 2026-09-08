#include "free_type.h"
#include "../harfbuzz/hb.h"
#include "../harfbuzz/hb-ft.h"
#include <stdbool.h>


#define     ATLAS_WITDH      512
#define     ATLAS_HEIGHT     512
#define     MAX_UNIQUE_GLYPHS 256

typedef struct {

    hb_buffer_t         *hb_buffer;
    hb_font_t           *hb_fonts;
    hb_glyph_info_t     *glyph_info;
    hb_glyph_position_t * glyph_pos;

} hb_rsrs;


// now the glyph info 
typedef struct {
    // glyph infomations from harfbuzz

    hb_codepoint_t glyphId;
    float x_advance;
    float y_advance;
    int   x_offset ;
    int   y_offset ;
    // the iner part of the square 
    int       height;
    int        width;
    int   top_offset;
    int  left_offset;



}glyph_infos;

typedef struct {

    bool is_cached;
    float u0,u1;
    float v0,v1;
    hb_codepoint_t glyphId;




}atlasTextureRegion;

// then create the atlas
typedef struct {

    unsigned char pixels [ATLAS_HEIGHT*ATLAS_WITDH];
    int cursor_x;
    int cursor_y;
    int row_max_height;
    atlasTextureRegion cache [MAX_UNIQUE_GLYPHS];


}TextureAtlas;



// create resources 
int create_resources (Font *font,hb_rsrs *hb_rs);
int create_shaping   (hb_rsrs *hb_rs ,char *text,Font *font);
int get_glyph_info   (glyph_infos * glyph_info,hb_rsrs *hb_rs,Font*font);
void atlas_init      (TextureAtlas *atlas);
atlasTextureRegion * atlas_get_or_pack (TextureAtlas *atlas,Font*font,hb_codepoint_t glyphId);




