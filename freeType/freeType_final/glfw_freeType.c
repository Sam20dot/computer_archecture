
// PolyLabEditor - Phase 1
// GLFW + FreeType + Sokol_gfx
//
// Flow:
//
//     Keyboard character
//            |
//            v
//        GLFW callback
//            |
//            v
//        FreeType glyph
//            |
//            v
//       Glyph bitmap
//            |
//            v
//       Sokol texture
//            |
//            v
//        GPU shader
//            |
//            v
//          Screen
//
// This version renders ONE glyph at a time.
// The latest character typed is displayed in the GLFW window.

#define SOKOL_IMPL
#define SOKOL_GLCORE

#include "./libs/sokol/sokol_gfx.h"
#include "./libs/sokol/sokol_log.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ============================================================
// FONT STATE
// ============================================================

typedef struct {
    FT_Library library;
    FT_Face    face;
} Font;

static Font font;


// ============================================================
// GPU OBJECTS
//
// These are created ONCE.
//
// We do NOT create shaders/pipelines every time a key is pressed.
// ============================================================

static sg_shader   g_shd;
static sg_pipeline g_pip;
static sg_sampler  g_smp;
static sg_buffer   g_vbuf;


// ============================================================
// CURRENT GLYPH
//
// Every time the user types a new character:
//
//     FreeType bitmap
//          |
//          v
//     new GPU image
//
// The previous image is destroyed first.
// ============================================================

static sg_image g_glyph_img  = {0};
static sg_view  g_glyph_view = {0};

static bool  g_has_glyph = false;
static float g_glyph_w   = 0.0f;
static float g_glyph_h   = 0.0f;


// ============================================================
// VERTEX SHADER PARAMETERS
// ============================================================

typedef struct {

    // Screen size in pixels
    float screen_w;
    float screen_h;

    // Glyph size in pixels
    float glyph_w;
    float glyph_h;

    // Glyph position in pixels
    float pos_x;
    float pos_y;

    // Padding
    float _pad0;
    float _pad1;

} vs_params_t;

static vs_params_t g_vs_params;


// ============================================================
// GLFW ERROR CALLBACK
// ============================================================

static void error_callback(int error,
                           const char *description)
{
    fprintf(stderr,
            "GLFW error %d: %s\n",
            error,
            description);
}


// ============================================================
// UPLOAD FREEYPE BITMAP TO GPU
// ============================================================

static void upload_glyph_bitmap(FT_Bitmap *bitmap)
{
    // Nothing to upload
    if (bitmap->width == 0 ||
        bitmap->rows == 0)
    {
        return;
    }


    // --------------------------------------------------------
    // Destroy previous glyph
    // --------------------------------------------------------

    if (g_has_glyph)
    {
        sg_destroy_view(g_glyph_view);
        sg_destroy_image(g_glyph_img);

        g_has_glyph = false;
    }


    // --------------------------------------------------------
    // FreeType bitmap information
    // --------------------------------------------------------

    unsigned char *pixels = bitmap->buffer;

    unsigned char *repacked = NULL;

    int abs_pitch =
        bitmap->pitch < 0
        ? -bitmap->pitch
        : bitmap->pitch;


    // --------------------------------------------------------
    // FreeType pitch can sometimes differ from width.
    //
    // Sokol needs tightly packed rows.
    // --------------------------------------------------------

    if (abs_pitch != (int)bitmap->width)
    {
        repacked =
            (unsigned char *)malloc(
                (size_t)bitmap->width *
                bitmap->rows
            );

        if (!repacked)
        {
            fprintf(stderr,
                    "Failed to allocate glyph bitmap memory\n");

            return;
        }


        for (unsigned int row = 0;
             row < bitmap->rows;
             row++)
        {
            memcpy(
                repacked + row * bitmap->width,

                bitmap->buffer + row * abs_pitch,

                bitmap->width
            );
        }


        pixels = repacked;
    }


    // --------------------------------------------------------
    // Create GPU image
    //
    // FreeType normal grayscale bitmap = one byte per pixel.
    //
    // Therefore:
    //
    //     R8
    //
    // --------------------------------------------------------

    g_glyph_img =
        sg_make_image(&(sg_image_desc)
        {
            .width =
                (int)bitmap->width,

            .height =
                (int)bitmap->rows,

            .pixel_format =
                SG_PIXELFORMAT_R8,

            .data.mip_levels[0] =
            {
                .ptr = pixels,

                .size =
                    (size_t)bitmap->width *
                    bitmap->rows,
            },

            .label =
                "glyph-texture",
        });


    // --------------------------------------------------------
    // Create Sokol view for the image
    // --------------------------------------------------------

    g_glyph_view =
        sg_make_view(&(sg_view_desc)
        {
            .texture.image =
                g_glyph_img,

            .label =
                "glyph-texture-view",
        });


    // --------------------------------------------------------
    // Repacked memory is no longer needed.
    //
    // Sokol has already copied the data into the GPU resource.
    // --------------------------------------------------------

    if (repacked)
    {
        free(repacked);
    }


    // --------------------------------------------------------
    // Save glyph dimensions
    // --------------------------------------------------------

    g_glyph_w =
        (float)bitmap->width;

    g_glyph_h =
        (float)bitmap->rows;


    g_has_glyph = true;
}


// ============================================================
// GLFW CHARACTER CALLBACK
// ============================================================

static void char_callback(GLFWwindow *window,
                          unsigned int codepoint)
{
    // --------------------------------------------------------
    // Convert Unicode codepoint into FreeType glyph index
    // --------------------------------------------------------

    int glyph_index =
        FT_Get_Char_Index(
            font.face,
            codepoint
        );


    printf(
        "the character values is : %c "
        "and its glyph index is : %d\n",
        codepoint,
        glyph_index
    );


    // --------------------------------------------------------
    // Load glyph
    // --------------------------------------------------------

    if (FT_Load_Glyph(
            font.face,
            glyph_index,
            FT_LOAD_DEFAULT) == FT_Err_Ok)
    {
        // ----------------------------------------------------
        // Convert outline into bitmap
        // ----------------------------------------------------

        FT_Render_Glyph(
            font.face->glyph,
            FT_RENDER_MODE_NORMAL
        );


        FT_GlyphSlot slot =
            font.face->glyph;


        // ----------------------------------------------------
        // Upload bitmap to GPU
        // ----------------------------------------------------

        upload_glyph_bitmap(
            &slot->bitmap
        );


        printf(
            "the glyph bitmap has been loaded "
            "within the memory !!!\n"
        );


        printf(
            "the character is : %c\n"
            "the slot bit map width: %d\n"
            "the slot bit map rows: %d\n",

            codepoint,

            slot->bitmap.width,

            slot->bitmap.rows
        );
    }


    fflush(stdout);

    (void)window;
}


// ============================================================
// CREATE GPU RESOURCES
//
// Called ONCE.
//
// Do NOT call this from char_callback().
// ============================================================

static void init_render_resources(void)
{
    // ========================================================
    // QUAD
    //
    // A simple rectangle:
    //
    //       0,0 -------- 1,0
    //        |             |
    //        |             |
    //       0,1 -------- 1,1
    //
    // This quad becomes the glyph rectangle.
    // ========================================================

    float quad[] =
    {
        // position      // UV

        0.0f, 0.0f,       0.0f, 0.0f,

        1.0f, 0.0f,       1.0f, 0.0f,

        1.0f, 1.0f,       1.0f, 1.0f,


        0.0f, 0.0f,       0.0f, 0.0f,

        1.0f, 1.0f,       1.0f, 1.0f,

        0.0f, 1.0f,       0.0f, 1.0f,
    };


    // ========================================================
    // VERTEX BUFFER
    // ========================================================

    g_vbuf =
        sg_make_buffer(&(sg_buffer_desc)
        {
            .data =
                SG_RANGE(quad),

            .label =
                "glyph-quad-vbuf",
        });


    // ========================================================
    // SAMPLER
    // ========================================================

    g_smp =
        sg_make_sampler(&(sg_sampler_desc)
        {
            .min_filter =
                SG_FILTER_LINEAR,

            .mag_filter =
                SG_FILTER_LINEAR,

            .wrap_u =
                SG_WRAP_CLAMP_TO_EDGE,

            .wrap_v =
                SG_WRAP_CLAMP_TO_EDGE,

            .label =
                "glyph-sampler",
        });


    // ========================================================
    // SHADER
    // ========================================================

    g_shd =
        sg_make_shader(&(sg_shader_desc)
        {
            // =================================================
            // VERTEX SHADER
            // =================================================

            .vertex_func.source =

                "#version 330\n"

                "uniform vec4 vs_params[2];\n"

                "layout(location=0) "
                "in vec2 in_pos;\n"

                "layout(location=1) "
                "in vec2 in_uv;\n"

                "out vec2 uv;\n"

                "void main() {\n"

                "    vec2 screen_size = "
                "vs_params[0].xy;\n"

                "    vec2 glyph_size = "
                "vs_params[0].zw;\n"

                "    vec2 glyph_pos = "
                "vs_params[1].xy;\n"

                "    vec2 pixel_pos = "
                "glyph_pos + "
                "in_pos * "
                "glyph_size;\n"

                "    vec2 ndc = "
                "(pixel_pos / screen_size) "
                "* 2.0 - 1.0;\n"

                "    ndc.y = -ndc.y;\n"

                "    gl_Position = "
                "vec4(ndc, 0.0, 1.0);\n"

                "    uv = in_uv;\n"

                "}\n",


            // =================================================
            // FRAGMENT SHADER
            // =================================================

            .fragment_func.source =

                "#version 330\n"

                "uniform sampler2D glyph_texture;\n"

                "uniform vec4 text_color;\n"

                "in vec2 uv;\n"

                "out vec4 frag_color;\n"

                "void main() {\n"

                "    float glyph_alpha = "
                "texture(glyph_texture, uv).r;\n"

                "    frag_color = "
                "vec4("
                "text_color.rgb, "
                "text_color.a * glyph_alpha"
                ");\n"

                "    if (frag_color.a < 0.01) {\n"

                "        discard;\n"

                "    }\n"

                "}\n",


            // =================================================
            // VERTEX ATTRIBUTES
            // =================================================

            .attrs =
            {
                [0] =
                {
                    .glsl_name =
                        "in_pos"
                },

                [1] =
                {
                    .glsl_name =
                        "in_uv"
                },
            },


            // =================================================
            // VERTEX UNIFORMS
            // =================================================

            .uniform_blocks[0] =
            {
                .stage =
                    SG_SHADERSTAGE_VERTEX,

                .layout =
                    SG_UNIFORMLAYOUT_STD140,

                .size =
                    sizeof(vs_params_t),

                .glsl_uniforms =
                {
                    [0] =
                    {
                        .type =
                            SG_UNIFORMTYPE_FLOAT4,

                        .array_count =
                            2,

                        .glsl_name =
                            "vs_params",
                    },
                },
            },


            // =================================================
            // FRAGMENT UNIFORMS
            // =================================================

            .uniform_blocks[1] =
            {
                .stage =
                    SG_SHADERSTAGE_FRAGMENT,

                .layout =
                    SG_UNIFORMLAYOUT_STD140,

                .size =
                    sizeof(float) * 4,

                .glsl_uniforms =
                {
                    [0] =
                    {
                        .type =
                            SG_UNIFORMTYPE_FLOAT4,

                        .array_count =
                            1,

                        .glsl_name =
                            "text_color",
                    },
                },
            },


            // =================================================
            // TEXTURE
            // =================================================

            .views[0].texture =
            {
                .stage =
                    SG_SHADERSTAGE_FRAGMENT,

                .image_type =
                    SG_IMAGETYPE_2D,

                .sample_type =
                    SG_IMAGESAMPLETYPE_FLOAT,
            },


            // =================================================
            // SAMPLER
            // =================================================

            .samplers[0] =
            {
                .stage =
                    SG_SHADERSTAGE_FRAGMENT,

                .sampler_type =
                    SG_SAMPLERTYPE_FILTERING,
            },


            // =================================================
            // TEXTURE + SAMPLER
            // =================================================

            .texture_sampler_pairs[0] =
            {
                .stage =
                    SG_SHADERSTAGE_FRAGMENT,

                .view_slot =
                    0,

                .sampler_slot =
                    0,

                .glsl_name =
                    "glyph_texture",
            },


            .label =
                "glyph-shader",
        });


    // ========================================================
    // PIPELINE
    // ========================================================

    g_pip =
        sg_make_pipeline(&(sg_pipeline_desc)
        {
            .shader =
                g_shd,


            // =================================================
            // VERTEX LAYOUT
            // =================================================

            .layout.attrs =
            {
                [0] =
                {
                    .format =
                        SG_VERTEXFORMAT_FLOAT2,
                },

                [1] =
                {
                    .format =
                        SG_VERTEXFORMAT_FLOAT2,
                },
            },


            // =================================================
            // ALPHA BLENDING
            // =================================================

            .colors[0] =
            {
                .blend =
                {
                    .enabled =
                        true,

                    .src_factor_rgb =
                        SG_BLENDFACTOR_SRC_ALPHA,

                    .dst_factor_rgb =
                        SG_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,

                    .op_rgb =
                        SG_BLENDOP_ADD,

                    .src_factor_alpha =
                        SG_BLENDFACTOR_ONE,

                    .dst_factor_alpha =
                        SG_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,

                    .op_alpha =
                        SG_BLENDOP_ADD,
                },
            },


            // =================================================
            // IMPORTANT:
            //
            // We are NOT using depth testing for text.
            // =================================================

            .depth =
            {
                .pixel_format =
                    SG_PIXELFORMAT_NONE,

                .write_enabled =
                    false,
            },


            .label =
                "text-pipeline",
        });
}


// ============================================================
// GPU CLEANUP
// ============================================================

static void shutdown_render_resources(void)
{
    if (g_has_glyph)
    {
        sg_destroy_view(
            g_glyph_view
        );

        sg_destroy_image(
            g_glyph_img
        );
    }


    sg_destroy_pipeline(g_pip);

    sg_destroy_shader(g_shd);

    sg_destroy_sampler(g_smp);

    sg_destroy_buffer(g_vbuf);
}


// ============================================================
// MAIN
// ============================================================

int main(void)
{
    // ========================================================
    // GLFW
    // ========================================================

    glfwSetErrorCallback(
        error_callback
    );


    if (!glfwInit())
    {
        printf(
            "\nfailed to initialize GLFW\n"
        );

        return 1;
    }


    // ========================================================
    // OPENGL 3.3 CORE
    // ========================================================

    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MAJOR,
        3
    );

    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MINOR,
        3
    );

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        GLFW_OPENGL_CORE_PROFILE
    );


    // ========================================================
    // CREATE WINDOW
    // ========================================================

    GLFWwindow *window =
        glfwCreateWindow(
            1200,
            800,
            "Sam - FreeType + Sokol",
            NULL,
            NULL
        );


    if (!window)
    {
        printf(
            "\nfailed to create window\n"
        );

        glfwTerminate();

        return 1;
    }


    glfwMakeContextCurrent(
        window
    );


    // ========================================================
    // FREETYPE
    // ========================================================

    char *pathname =
        "/usr/share/fonts/truetype/ubuntu/UbuntuMono-RI.ttf";


    int libraryInit =
        FT_Init_FreeType(
            &font.library
        );


    if (libraryInit == FT_Err_Ok)
    {
        printf(
            "\nthe library initialized\n"
        );
    }
    else
    {
        printf(
            "\nFreeType library initialization failed\n"
        );

        glfwDestroyWindow(window);

        glfwTerminate();

        return 1;
    }


    int faceInit =
        FT_New_Face(
            font.library,
            pathname,
            0,
            &font.face
        );


    if (faceInit == FT_Err_Ok)
    {
        printf(
            "\nthe face has been created\n"
        );
    }
    else
    {
        printf(
            "\nfailed to create font face\n"
        );

        FT_Done_FreeType(
            font.library
        );

        glfwDestroyWindow(window);

        glfwTerminate();

        return 1;
    }


    // ========================================================
    // FONT SIZE
    //
    // Glyphs will be rendered at 48 pixels.
    // ========================================================

    FT_Set_Pixel_Sizes(
        font.face,
        0,
        48
    );


    printf(
        "\n"
        "_____ WELCOME TO THE COMBINATION OF "
        "GLFW + FREETYPE + SOKOL _____\n\n"
    );


    printf(
        "Type a character.\n"
        "GLFW receives it.\n"
        "FreeType creates the glyph bitmap.\n"
        "Sokol sends the bitmap to the GPU.\n"
        "The shader renders it on the screen.\n\n"
    );


    // ========================================================
    // SOKOL SETUP
    //
    // IMPORTANT:
    //
    // There is NO depth buffer.
    //
    // This must match:
    //
    //     pipeline.depth.pixel_format
    //              =
    //     SG_PIXELFORMAT_NONE
    //
    // ========================================================

    sg_setup(&(sg_desc)
    {
        .environment =
        {
            .defaults =
            {
                .color_format =
                    SG_PIXELFORMAT_RGBA8,

                .depth_format =
                    SG_PIXELFORMAT_NONE,

                .sample_count =
                    1,
            },
        },

        .logger.func =
            slog_func,
    });


    // ========================================================
    // CREATE GPU RESOURCES
    // ========================================================

    init_render_resources();


    // ========================================================
    // PASS ACTION
    //
    // Clear background.
    // ========================================================

    sg_pass_action pass_action =
    {
        .colors[0] =
        {
            .load_action =
                SG_LOADACTION_CLEAR,

            .clear_value =
            {
                0.05f,
                0.05f,
                0.08f,
                1.0f
            },
        },
    };


    // ========================================================
    // GLFW CHARACTER CALLBACK
    // ========================================================

    glfwSetCharCallback(
        window,
        char_callback
    );


    // ========================================================
    // MAIN RENDER LOOP
    // ========================================================

    while (!glfwWindowShouldClose(window))
    {
        int width;
        int height;


        glfwGetFramebufferSize(
            window,
            &width,
            &height
        );


        // ====================================================
        // BEGIN SOKOL PASS
        //
        // IMPORTANT:
        //
        // depth_format = NONE
        //
        // This now matches the pipeline.
        // ====================================================

        sg_begin_pass(&(sg_pass)
        {
            .swapchain =
            {
                .color_format =
                    SG_PIXELFORMAT_RGBA8,

                .depth_format =
                    SG_PIXELFORMAT_NONE,

                .width =
                    width,

                .height =
                    height,

                .sample_count =
                    1,
            },

            .action =
                pass_action,
        });


        // ====================================================
        // DRAW GLYPH
        // ====================================================

        if (g_has_glyph)
        {
            // -----------------------------------------------
            // Tell vertex shader:
            //
            // screen size
            // glyph size
            // glyph position
            // -----------------------------------------------

            g_vs_params =
            (vs_params_t)
            {
                .screen_w =
                    (float)width,

                .screen_h =
                    (float)height,

                .glyph_w =
                    g_glyph_w,

                .glyph_h =
                    g_glyph_h,

                .pos_x =
                    50.0f,

                .pos_y =
                    50.0f,
            };


            // -----------------------------------------------
            // Glyph color
            //
            // White
            // -----------------------------------------------

            float text_color[4] =
            {
                1.0f,
                1.0f,
                1.0f,
                1.0f
            };


            // -----------------------------------------------
            // Pipeline
            // -----------------------------------------------

            sg_apply_pipeline(
                g_pip
            );


            // -----------------------------------------------
            // Vertex buffer
            // Glyph texture
            // Sampler
            // -----------------------------------------------

            sg_apply_bindings(
                &(sg_bindings)
                {
                    .vertex_buffers[0] =
                        g_vbuf,

                    .views[0] =
                        g_glyph_view,

                    .samplers[0] =
                        g_smp,
                }
            );


            // -----------------------------------------------
            // Vertex shader uniforms
            // -----------------------------------------------

            sg_apply_uniforms(
                0,
                &SG_RANGE(g_vs_params)
            );


            // -----------------------------------------------
            // Fragment shader uniforms
            // -----------------------------------------------

            sg_apply_uniforms(
                1,
                &SG_RANGE(text_color)
            );


            // -----------------------------------------------
            // DRAW
            //
            // 6 vertices = 2 triangles = 1 rectangle
            // -----------------------------------------------

            sg_draw(
                0,
                6,
                1
            );
        }


        // ====================================================
        // END PASS
        // ====================================================

        sg_end_pass();


        // ====================================================
        // SUBMIT GPU COMMANDS
        // ====================================================

        sg_commit();


        // ====================================================
        // GLFW EVENTS
        // ====================================================

        glfwPollEvents();


        // ====================================================
        // PRESENT WINDOW
        // ====================================================

        glfwSwapBuffers(
            window
        );
    }


    // ========================================================
    // CLEANUP
    // ========================================================

    shutdown_render_resources();

    sg_shutdown();


    FT_Done_Face(
        font.face
    );

    FT_Done_FreeType(
        font.library
    );


    glfwDestroyWindow(
        window
    );

    glfwTerminate();


    return 0;
}

