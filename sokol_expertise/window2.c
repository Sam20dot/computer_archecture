#define SOKOL_IMPL
#define SOKOL_GFX_IMPL
#define SOKOL_GLCORE

#include "./libs/sokol/sokol_gfx.h"
#include "./include/error_callback.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h> // Required for sinf() and cosf()

int main () {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        printf("failed to initiate the glfw library\n");
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1200, 800, "PolyLab - Dynamic Streaming", NULL, NULL);
    if (!window) {
        printf("failed to create window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    sg_setup(&(sg_desc) {
        .environment = {
            .defaults = {
                .color_format = SG_PIXELFORMAT_RGBA8,
                .depth_format = SG_PIXELFORMAT_DEPTH_STENCIL,
                .sample_count = 1
            }
        }
    });

    // Explicit size calculation for 3 corners (vertices) * 7 properties (floats) per corner
    size_t buffer_size = 3 * 7 * sizeof(float); 

    // ✅ FIXED SECTION: The missing parameters are safely restored here
    sg_buffer buf_id = sg_make_buffer(&(sg_buffer_desc) {
                 // Tells Sokol to skip VRAM structural locking
            .usage = {
        .vertex_buffer = true,      // 👈 Tells Sokol it contains vertex properties
        .dynamic_update = true     // 👈 Tells Sokol this data will stream across PCIe
    },
    .size = buffer_size    // Establishes maximum PCIe packet size
    });

    sg_shader shd_id = sg_make_shader(&(sg_shader_desc) {
        .vertex_func.source =
        "#version 330\n"
        "layout(location=0) in vec3 position;\n"
        "layout(location=1) in vec4 color0;\n"
        "out vec4 color;\n"
        "void main() {\n"
        "  gl_Position = vec4(position, 1.0);\n"
        "  color = color0;\n"
        "}\n",
        .fragment_func.source =
        "#version 330\n"
        "in vec4 color;\n"
        "out vec4 frag_color;\n"
        "void main() {\n"
        "  frag_color = color;\n"
        "}\n" 
    });

    sg_pipeline pipe_id = sg_make_pipeline(&(sg_pipeline_desc) {
        .shader = shd_id,
        .layout = {
            .attrs = {
                [0] = {.format = SG_VERTEXFORMAT_FLOAT3},
                [1] = {.format = SG_VERTEXFORMAT_FLOAT4}
            }
        }
    });

    sg_bindings bind = {
        .vertex_buffers[0] = buf_id
    };

    sg_pass_action pass_action = {
        .colors[0] = {
            .load_action = SG_LOADACTION_CLEAR,
            .clear_value = {0.1f, 0.3f, 0.4f, 1.0f} // Dark teal background
        }
    };

    float timer = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        // 1. Mutate the triangle offset coordinates in local system memory
        timer += 0.02f; 
        float offset_x = sinf(timer) * 0.3f; 
        float offset_y = cosf(timer) * 0.3f; 

        float dynamic_vertices[] = {
            // position                          // color 
             0.0f + offset_x,  0.5f + offset_y, 0.1f,  0.9f, 0.4f, 1.0f, 1.0f,
            -0.5f + offset_x, -0.5f + offset_y, 0.1f,  0.1f, 0.3f, 1.0f, 1.0f,
             0.5f + offset_x, -0.5f + offset_y, 0.1f,  0.5f, 0.1f, 1.0f, 1.0f
        };

        // 2. Stream the mutated data directly down the PCIe bus
        sg_update_buffer(buf_id, &SG_RANGE(dynamic_vertices));

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        sg_begin_pass(&(sg_pass) {
            .action = pass_action,
            .swapchain = {
                .width = width,
                .height = height,
                .sample_count = 1,
                .color_format = SG_PIXELFORMAT_RGBA8,
                .depth_format = SG_PIXELFORMAT_DEPTH_STENCIL,
                .gl.framebuffer = 0
            }
        });
        
        sg_apply_pipeline(pipe_id);
        sg_apply_bindings(&bind);
        sg_draw(0, 3, 1);
        
        sg_end_pass();
        sg_commit();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
