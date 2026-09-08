
#define SOKOL_GLCORE
#define SOKOL_IMPL


#include "../include/sokol_gfx.h"

void sokol_init_graphic() {


  sg_setup(&(sg_desc){

      .environment =
          {

              .defaults =
                  {

                      .color_format = SG_PIXELFORMAT_RGBA8,
                      .depth_format = SG_PIXELFORMAT_DEPTH_STENCIL,
                      .sample_count = 1}},
      .logger = slog_func

  });

// imediatly check 
   if (!sg_isvalid()) {
       printf ("\n SOKOL INITILIZED FAILED\n");
       return ;


   }
   else {

       printf ("\n SOKOL INITLIZED SUCCESSFULLY\n");

   }

}


sg_image upload_atlas_to_gpu(TextureAtlas *atlas) {
     const size_t explicit_surface_size = 512 * 512;
  sg_image atlas_texture = sg_make_image(&(sg_image_desc){


      .pixel_format=SG_PIXELFORMAT_R8,
      .width = 512,
      .height = 512,
      .usage.immutable = true,
      .type = SG_IMAGETYPE_2D,
      .data =
          (sg_image_data){

              .mip_levels[0] =
                  (sg_range){

                      .ptr = atlas->pixels, .size = explicit_surface_size
                  }},
      .label = "plab data upload"

  });
sg_resource_state state = sg_query_image_state(atlas_texture);

if (state != SG_RESOURCESTATE_VALID) {
    printf("ATLAS GPU UPLOAD FAILED!\n");
} else {
    printf("ATLAS GPU UPLOAD SUCCESS!\n");
}
  return atlas_texture;
}

sg_buffer create_vertex_buffer(Quard *quard_square, int quard_count) {
    size_t total_bytes = quard_count * sizeof(Quard);

    sg_buffer buffer= sg_make_buffer(&(sg_buffer_desc){
        .size = total_bytes, // Set total memory track allocation capacity
        
        // Match the modern nested boolean usage block layout format
        .usage = {
            .vertex_buffer = true, // Replaces SG_BUFFERTYPE_VERTEXBUFFER!
            .dynamic_update = true // Essential flag since PLab text updates frame-by-frame
        },

        // Pass down your flat memory array layout using standard range casts
     
        
        .label = "PLab-Dynamic-Vertex-Buffer"
    });
    if (sg_query_buffer_state(buffer)
        != SG_RESOURCESTATE_VALID) {

        printf("VERTEX BUFFER CREATION FAILED!\n");

    } else {

        printf(
            "VERTEX BUFFER CREATED: %zu bytes\n",
            total_bytes
        );
    }
    return buffer;

}

// here we create a function for helping us to shape the triangles 

// Generates the flat list of Quards mapping directly to screen & texture triangles
int build_line_triangles(glyph_infos *glyphs, int glyph_count, TextureAtlas *atlas, Quard *out_quads,Font * font) {
    float pen_x = 0.0f;
    float pen_y = 120.0f; // Baseline row starting coordinate pixel height
    int quad_idx = 0;

    for (int i = 0; i < glyph_count; i++) {
        // 1. Fetch moving texture percentage limits out of your working cache table
        atlasTextureRegion *reg = atlas_get_or_pack(atlas, font, glyphs[i].glyphId);
        if (!reg) continue;

        // 2. Compute spatial screen box corners using your verified metrics variables
        float x0 = pen_x + glyphs[i].x_offset + glyphs[i].left_offset;
        float y0 = pen_y - glyphs[i].top_offset + glyphs[i].y_offset;
        float x1 = x0 + glyphs[i].width;
        float y1 = y0 + glyphs[i].height;

        // 3. Only generate triangles if it's a visible geometry character (skips spaces)
        if (glyphs[i].width > 0 && glyphs[i].height > 0) {
            
            // --- TRIANGLE 1 (Top-Left, Top-Right, Bottom-Left) ---
            out_quads[quad_idx++] = (Quard){ .u0 = reg->u0, .u1 = reg->u1, .v0 = reg->v0, .v1 = reg->v1, .x0 = x0, .x1 = x1, .y0 = y0, .y1 = y1 }; // Vert 1
            out_quads[quad_idx++] = (Quard){ .u0 = reg->u0, .u1 = reg->u1, .v0 = reg->v0, .v1 = reg->v1, .x0 = x0, .x1 = x1, .y0 = y0, .y1 = y1 }; // Vert 2
            out_quads[quad_idx++] = (Quard){ .u0 = reg->u0, .u1 = reg->u1, .v0 = reg->v0, .v1 = reg->v1, .x0 = x0, .x1 = x1, .y0 = y0, .y1 = y1 }; // Vert 3

            // --- TRIANGLE 2 (Bottom-Left, Top-Right, Bottom-Right) ---
            out_quads[quad_idx++] = (Quard){ .u0 = reg->u0, .u1 = reg->u1, .v0 = reg->v0, .v1 = reg->v1, .x0 = x0, .x1 = x1, .y0 = y0, .y1 = y1 }; // Vert 3 Copy
            out_quads[quad_idx++] = (Quard){ .u0 = reg->u0, .u1 = reg->u1, .v0 = reg->v0, .v1 = reg->v1, .x0 = x0, .x1 = x1, .y0 = y0, .y1 = y1 }; // Vert 2 Copy
            out_quads[quad_idx++] = (Quard){ .u0 = reg->u0, .u1 = reg->u1, .v0 = reg->v0, .v1 = reg->v1, .x0 = x0, .x1 = x1, .y0 = y0, .y1 = y1 }; // Vert 4
        }

        // 4. Step your horizontal pencil advances exactly like your console logs did!
        pen_x += glyphs[i].x_advance;
        pen_y += glyphs[i].y_advance;
    }

    return quad_idx; // Returns total processed triangle vertex corners count!
}
sg_pass_action background_color () {

    sg_pass_action bck_color={

        .colors[0]= {

            .load_action=SG_LOADACTION_CLEAR,
            .clear_value={ 0.11f, 0.12f, 0.13f, 1.0f } 
            
        }
    };
    return bck_color;


}

sg_pipeline text_pipeline () {

    sg_shader shd=sg_make_shader (&(sg_shader_desc) {

            .vertex_func.source=
             "#version 330\n"
             "uniform vec2 u_screen_size;\n"
   
    // Each corner input receives all 8 floats of the Quard struct at location 0 and 1
    "layout(location=0) in vec4 attr_uv;\n"   // holds: u0, u1, v0, v1
    "layout(location=1) in vec4 attr_pos;\n"  // holds: x0, x1, y0, y1
    "out vec2 uv;\n"
    "void main() {\n"
    "    int corner = gl_VertexID % 6;\n"
    "    float x = 0.0; float y = 0.0;\n"
    "    \n"
    "    // Explicitly reconstruct the 2 distinct triangles (6 corners) from the bounding boxes\n"
    "    if (corner == 0) { x = attr_pos.x; y = attr_pos.z; uv = vec2(attr_uv.x, attr_uv.z); } // Top-Left\n"
    "    if (corner == 1) { x = attr_pos.y; y = attr_pos.z; uv = vec2(attr_uv.y, attr_uv.z); } // Top-Right\n"
    "    if (corner == 2) { x = attr_pos.x; y = attr_pos.w; uv = vec2(attr_uv.x, attr_uv.w); } // Bottom-Left\n"
    "    if (corner == 3) { x = attr_pos.x; y = attr_pos.w; uv = vec2(attr_uv.x, attr_uv.w); } // Bottom-Left Copy\n"
    "    if (corner == 4) { x = attr_pos.y; y = attr_pos.z; uv = vec2(attr_uv.y, attr_uv.z); } // Top-Right Copy\n"
    "    if (corner == 5) { x = attr_pos.y; y = attr_pos.w; uv = vec2(attr_uv.y, attr_uv.w); } // Bottom-Right\n"
    "    \n"
    "    // Transform pixel canvas values smoothly to normalized GPU clip space (-1.0 to 1.0)\n"
    "    float ndc_x = (x /u_screen_size.x) * 2.0 - 1.0;\n"
    "    float ndc_y = 1.0 - (y /u_screen_size.y) * 2.0;\n"
    "    gl_Position = vec4(ndc_x, ndc_y, 0.0, 1.0);\n"
    "}\n",
        .fragment_func.source=
             "#version 330\n"
    "uniform sampler2D tex;\n"
    "in vec2 uv;\n"
    "out vec4 frag_color;\n"
    "void main() {\n"
    "    float text_alpha = texture(tex, uv).r;\n" // Sample R8 channel
    "    vec3 text_color = vec3(0.95, 0.95, 0.95);\n" // Off-white code ink
    "    frag_color = vec4(text_color, text_alpha);\n"
    "}\n",

    .uniform_blocks = {
    [0] = {
        .stage = SG_SHADERSTAGE_VERTEX,
        .size = 16,
        .layout=SG_UNIFORMLAYOUT_STD140,


        .glsl_uniforms = {
            [0] = {
                .glsl_name = "u_screen_size",
                .type = SG_UNIFORMTYPE_FLOAT2,
                .array_count = 1
            }
        }
    }
},
.views = {
    [0] = {
        .texture = {
            .stage = SG_SHADERSTAGE_FRAGMENT,
            .image_type = SG_IMAGETYPE_2D,
            .sample_type = SG_IMAGESAMPLETYPE_FLOAT,
            .multisampled = false
        }
    }
},

.samplers = {
    [0] = {
        .stage = SG_SHADERSTAGE_FRAGMENT,
        .sampler_type = SG_SAMPLERTYPE_FILTERING
    }
},

.texture_sampler_pairs = {
    [0] = {
        .stage = SG_SHADERSTAGE_FRAGMENT,
        .view_slot = 0,
        .sampler_slot = 0,
        .glsl_name = "tex"
    }
},

       
            });
printf("shader valid: %d\n", sg_query_shader_state(shd) == SG_RESOURCESTATE_VALID);
 sg_pipeline pipe=sg_make_pipeline (& (sg_pipeline_desc) {

         .shader=shd,
         .primitive_type=SG_PRIMITIVETYPE_TRIANGLES,
         // THEN STRUCTURE 
         .layout= (sg_vertex_layout_state) {

           .buffers[0]={.stride=sizeof (Quard)},
           .attrs= {
              [0]={.buffer_index=0,.offset=0,.format=SG_VERTEXFORMAT_FLOAT4},
              [1]={.buffer_index=0,.offset=sizeof(float)*4,.format=SG_VERTEXFORMAT_FLOAT4}

           }
         },
         
     
        
         .color_count=1,
         .colors[0]= (sg_color_target_state) {
            .pixel_format=SG_PIXELFORMAT_RGBA8,
            .blend = (sg_blend_state){
                    .enabled = true,
                    .src_factor_rgb = SG_BLENDFACTOR_SRC_ALPHA,
                    .dst_factor_rgb = SG_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
                    .src_factor_alpha = SG_BLENDFACTOR_ONE,
                    .dst_factor_alpha = SG_BLENDFACTOR_ZERO
                }

         },
         .label= "play_gemetry_pipeline"

                  });
 return pipe;



 
}
sg_sampler make_sampler () {

    sg_sampler sampler=sg_make_sampler (&(sg_sampler_desc) {

            // Create the standalone Sampler object to handle font texture filtering rules
    .min_filter = SG_FILTER_LINEAR,      // Smooth out characters when scaled down
    .mag_filter = SG_FILTER_LINEAR,      // Smooth out characters when scaled up
    .wrap_u     = SG_WRAP_CLAMP_TO_EDGE, // Prevents texture bleeding on the left/right walls
    .wrap_v     = SG_WRAP_CLAMP_TO_EDGE, // Prevents texture bleeding on the top/bottom walls
    .label      = "PLab-Font-Atlas-Sampler"
});


       return sampler;


}

void render_text_line(sg_buffer dynamic_vbuf,sg_view atlas_views,sg_sampler atlas_sampler, int total_corners) {
    // 1. Map your active resources straight into the bindings structure blocks
  
    sg_bindings bindings = (sg_bindings){
        .vertex_buffers[0] = dynamic_vbuf, // Index 0 maps to vertex buffer slot 0
        .views         [0] =atlas_views,
        .samplers      [0] =atlas_sampler
          };

    // 2. Commit your bindings array layout slots directly to the GPU
    sg_apply_bindings(&bindings);

    // 3. Fire the execution batch to render the triangles!
    sg_draw(0, total_corners, 1);
}


