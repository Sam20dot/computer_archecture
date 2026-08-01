#define SOKOL_IMPL 
#define SOKOL_GFX_IMPL
#define SOKOL_GLCORE
#include "./libs/sokol/sokol_gfx.h"
#include <GLFW/glfw3.h>
#include "./include/error_callback.h"
#include <stdio.h>
#include <stdlib.h> // Required for setenv()

int main () {
    // 💡 FORCE WSL COMPATIBILITY FLAGGING BEFORE DOING ANYTHING ELSE:
    // This tells the Linux driver inside WSL to use software emulation 
    // if hardware acceleration locks up. This stops the "core dump" crash.
    setenv("LIBGL_ALWAYS_SOFTWARE", "1", 1);

    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit()) {
        printf("failed to initialize glfw library\n");
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1200, 800, "PolyLab", NULL, NULL);
    if (!window) {
        printf("window failed to load!!\n");
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

    float vertex[] = {
         0.0f,  0.5f, 0.2f,       1.0f, 0.1f, 0.2f, 1.0f,
        -0.5f, -0.5f, 0.2f,       1.0f, 0.1f, 0.2f, 1.0f,
         0.5f, -0.5f, 0.2f,       1.0f, 0.1f, 0.2f, 1.0f,
    };

    // ✅ FIXED: Added explicit modern usage layout block matching your header version
    sg_buffer buf_id = sg_make_buffer(&(sg_buffer_desc){
        .usage = {
            .vertex_buffer = true
        },
        .data = SG_RANGE(vertex)
    });

    sg_shader shd_id = sg_make_shader(&(sg_shader_desc){
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

    sg_pipeline pip_id = sg_make_pipeline(&(sg_pipeline_desc){
        .shader = shd_id,
        .layout = {
            .attrs = {
                [0]= { .format = SG_VERTEXFORMAT_FLOAT3 }, 
                [1]= { .format = SG_VERTEXFORMAT_FLOAT4 }  
            }
        }
    });

    // ✅ FIXED: Full structural union targeting for bindings array
    sg_bindings binds = {
        .vertex_buffers = buf_id
    };

    // ✅ FIXED: Full structural layout configuration for background pass color targets
    sg_pass_action pass_action = {
        .colors[0] = {
            .load_action = SG_LOADACTION_CLEAR,
            .clear_value = { 0.1f, 0.7f, 0.1f, 1.0f } // Dark Green
        }
    };

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        sg_begin_pass(&(sg_pass){
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

        sg_apply_pipeline(pip_id);
        sg_apply_bindings(&binds);
        sg_draw(0, 3, 1); 

        sg_end_pass();
        sg_commit();

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

