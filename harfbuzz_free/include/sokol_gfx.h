
#pragma once


#include "../libs/sokol_gfx.h"
#include "../libs/sokol_log.h"
#include "text_render.h"
#include "harfbuzz.h"
typedef struct {

    float u0,u1;
    float v0,v1;
    float x0,x1;
    float y0,y1;



}Quard;



void            sokol_init_graphic    ();
sg_image        upload_atlas_to_gpu   ( TextureAtlas * atlas);
sg_buffer       create_vertex_buffer  ( Quard *quard_square,
                                        int quard_count);
int             build_line_triangles  ( glyph_infos *glyphs,
                                        int glyph_count,
                                        TextureAtlas *atlas,
                                        Quard *out_quads,
                                        Font*font);
void            render_text_line      ( sg_buffer dynamic_vbuf,
                                       sg_view atlas_views,
                                        sg_sampler atlas_sampler, 
                                        int total_corners);
sg_sampler      make_sampler ();
sg_pipeline     text_pipeline ();
sg_pass_action  background_color();






