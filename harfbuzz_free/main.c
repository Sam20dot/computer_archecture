#include "./include/text_render.h"
#include "./include/sokol_gfx.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

// First create the global subsystem objects 
Font font;
hb_rsrs hb_rs;
glyph_infos glyph_info[MAX_UNIQUE_GLYPHS];
atlasTextureRegion cache[MAX_UNIQUE_GLYPHS];
TextureAtlas atlas;

// A solid continuous block array to store our streaming vertex corners safely
Quard outquard[MAX_UNIQUE_GLYPHS * 6];

int main () {
    // 1. Initialize GLFW Core Windowing Subsystems
    initilize_glfw();

    char* pathname = "/usr/share/fonts/truetype/ubuntu/Ubuntu-C.ttf";

    // 2. Initialize font library context structures
    free_type_init(&font, pathname, 64);
    
    GLFWwindow* window = glfwCreateWindow(1200, 800, "SAM_EDITOR", NULL, NULL);
    if (!window) {
        printf("\n Error: Failed to create GLFW window! \n");
        glfwTerminate();
        return -1;
    }
    
    // Explicitly bind the active context BEFORE waking up Sokol pipeline assets
    glfwMakeContextCurrent(window);
    sokol_init_graphic();

    // 3. Shape the text line using your HarfBuzz backend layout engine
    create_resources(&font, &hb_rs);
    create_shaping(&hb_rs, "we are here ", &font);
    
    // FIX A: Capture the EXACT number of active characters populated by HarfBuzz (returns 12)
     get_glyph_info(glyph_info, &hb_rs, &font);
    
    // Initialize our memory bitmap allocation atlas grid
    atlas_init(&atlas);
    printf("\n atlas initialized !!\n");

    // FIX B: Restrict the loop bounds to total_shaped_chars to keep memory lookups safe!
    for (int i = 0; i < 12; i++) { 
        atlasTextureRegion* atlas_cache = atlas_get_or_pack(&atlas, &font, glyph_info[i].glyphId);

        if (atlas_cache != NULL) {
            printf("\n--- Character Index %d (Glyph ID: %u) ---\n", i, atlas_cache->glyphId);
            printf("the uv coordinates are u0 :%f u1:%f\n", atlas_cache->u0, atlas_cache->u1);
            printf("the uv coordinates are v0 :%f v1:%f\n", atlas_cache->v0, atlas_cache->v1);
        }
    }

    // FIX C: Pass the true character length to compute layout boundaries warning-free
    int total_quard_corner = build_line_triangles(glyph_info,12, &atlas, outquard, &font);

    // FIX D: Size your GPU vertex buffer capacity matching the exact number of populated corners!
    sg_buffer vbuf = create_vertex_buffer(outquard, total_quard_corner);
    
    // 4. Create and upload rendering assets down to the GPU driver channel
    sg_image image = upload_atlas_to_gpu(&atlas);
    sg_pipeline pipe = text_pipeline();
    sg_pass_action pass_action = background_color();
    sg_sampler samplers = make_sampler();

    sg_view atlas_view=sg_make_view (&(sg_view_desc) {

            .texture={

              .image=image,

            },
              .label = "PLab-Font-Atlas-View"

            });
 

    // 5. Interactive real-time window canvas frame tick loop
    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
         if (total_quard_corner> 0) {
        sg_update_buffer(vbuf, &(sg_range){
            .ptr = outquard,
            .size = total_quard_corner * sizeof(Quard)
        });

    }
     float screen_uniforms[4] = { (float)width, (float)height,0.0f,0.0f};

        
              sg_begin_pass(&(sg_pass) {
            .action = pass_action,
            .swapchain = {
                .color_format = SG_PIXELFORMAT_RGBA8,
                .depth_format = SG_PIXELFORMAT_DEPTH_STENCIL,
                .sample_count = 1,
                .width = width,
                .height = height,
                
            }
        });

         sg_apply_pipeline(pipe);
       sg_apply_uniforms(0, &(sg_range){ .ptr = screen_uniforms, .size = sizeof(screen_uniforms) });
        // Open the frame drawing context pipeline pass bloc

       

        // Render the triangles in one single, high-performance hardware accelerated draw step batch!
        render_text_line(vbuf, atlas_view, samplers, total_quard_corner);
                             
        sg_end_pass();
        sg_commit();

         
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
     
    // 6. Resource cleanup shutdown sequence
    sg_shutdown();
    close_window(window); // Replace with standard glfwDestroyWindow(window) if needed

    return 0;
}

