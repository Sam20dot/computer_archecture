
#define SOKOL_IMPL
#define SOKOL_GLCORE
#include "../libs/sokol/sokol_gfx.h"
#include "../libs/sokol/sokol_log.h"
#include  <stdio.h>

#include <GLFW/glfw3.h>
#include "../include/callback.h"
// sokol files 



int main () {

    glfwSetErrorCallback (error_callback);
    if (!glfwInit()) {
        printf ("failed ot initilatize");
        return -1;

    }
    // then we are about to keep going 
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    // window creation 
    GLFWwindow *window = glfwCreateWindow (1200,800,"sam_repeat",NULL,NULL);
    // then we check if window has been created 
    if (!window) {

        printf ("\n window has been failed to initlized\n ");


    }

    // then make the window context 
    glfwMakeContextCurrent (window);

    // then setup the sg
    sg_setup  (& (sg_desc) {

            .environment= {
            .defaults= {
             .color_format= SG_PIXELFORMAT_RGBA8,
             .depth_format= SG_PIXELFORMAT_DEPTH_STENCIL,
             .sample_count=1

            }}

            });
    sg_pass_action pass_action = (sg_pass_action) {
        .colors[0] ={
            .load_action=SG_LOADACTION_CLEAR,
            .clear_value= {0.1f,0.3f,0.4f,0.8f}



        }

    };
sg_buffer vbuffer= sg_make_buffer (&(sg_buffer_desc) {

        .data=SG_RANGE(vbuffer),
        .usage.vertex_buffer=true,
        .label="points"

         });

    // then we can go to pass thea ction within themain 
    sg_shader shd = sg_make_shader(&(sg_shader_desc){
    .vertex_func.source = 
        "#version 330 core\n"
        "layout(location = 0) in vec3 position;\n"
        "void main() {\n"
        "    gl_Position = vec4(position, 1.0);\n"
        "    gl_PointSize = 1000.0;\n"
        "}\n",
    .fragment_func.source = 
        "#version 330 core\n"
        "out vec4 frag_color;\n"
        "void main() {\n"
        "    frag_color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n",
    .label = "point-shader"
});

// then pipeline to show that and do other configurations 
sg_pipeline pipe =sg_make_pipeline (&(sg_pipeline_desc) {
        .shader=shd,
        .primitive_type=SG_PRIMITIVETYPE_POINTS,
        .label="points",

        .layout= {

         .attrs[0].format=SG_VERTEXFORMAT_FLOAT3,

        }
               });
sg_bindings bind = {

    .vertex_buffers[0]=vbuffer

};


    while (!glfwWindowShouldClose (window)) {
          int height,width;
                glfwGetWindowSize (window, &width, &height);
                sg_begin_pass (&(sg_pass) {
                        .swapchain= {
                        .color_format=SG_PIXELFORMAT_RGBA8,
                        .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
                        .width=width,
                        .height=height,
                        .sample_count=1,

                        },
                        .action=pass_action
                        
                        
                        });

                sg_apply_pipeline (pipe);
                sg_apply_bindings (&bind);
                sg_draw (0,1,1);
                sg_end_pass ();
                sg_commit ();
                glfwSwapBuffers (window);
                glfwPollEvents ();





      
    }
sg_shutdown ();
glfwDestroyWindow (window);
glfwTerminate ();

}
