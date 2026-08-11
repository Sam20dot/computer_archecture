#define SOKOL_IMPL
#define SOKOL_GLCORE
#include "../libs/sokol/sokol_gfx.h"
#include "../libs/sokol/sokol_log.h"
#include "./include/callback.h"
#include <GLFW/glfw3.h>

#include <stdio.h>



// then we are to add the glfw and make the the window 
int main  () {

    glfwSetErrorCallback (error_callback);
    if (!glfwInit ()) {

        printf ("\n the glfw dfailed to initlized \n");
        return -1;

    }
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    //NOW WE CARE ABOUT TO CREATE THE FUNCTIONS 
    GLFWwindow *window=glfwCreateWindow (1200,800,"SAM PRAY",NULL,NULL);


    if (!window) {

        printf ("window has been failed to open the window ");
        return -1;
    }
    glfwMakeContextCurrent (window);
    sg_setup (& (sg_desc) {
            .environment= {

            .defaults= {

             .color_format=SG_PIXELFORMAT_RGBA8,
             .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
             .sample_count=1,

            }

            },
            .logger.func =slog_func,
            });

    float point[]= {
        // position 
        0.0f,0.0f,0.4f,  0.2f,0.4f,0.6f,0.89f,
        0.9f,0.0f,0.5f,  0.8f,0.3f,0.4f,0.4f,
        -0.90f,0.0f,0.7f,  0.7f,0.32f,0.98f,0.76f
       
    };

    sg_buffer pointBuffer= sg_make_buffer (& (sg_buffer_desc) {
            .usage.vertex_buffer=true,

            .data=SG_RANGE(point)
            

            });
    sg_shader  shd= sg_make_shader (& (sg_shader_desc) {
 
            .vertex_func.source= 
            "#version 330 core \n"
            "layout (location=0) in vec3 a_pos;\n"
            "layout (location=1) in vec4 a_color;\n"
            "out vec4 color;\n"
            "void main () {\n"
            "gl_Position=vec4(a_pos,1.0);\n"
            "color=a_color;\n"
            "gl_PointSize=5000.0 ;\n"
            
            "} \n",
            
            .fragment_func.source=
            "#version 330 core \n"
            "out vec4 fragColor ;\n"
            "in vec4 color;\n"
            "void main  () { \n"
            "fragColor=color;\n"
            
            "}\n",
            .attrs[0].glsl_name="a_pos",
            .attrs[1].glsl_name="a_color"

            });
    sg_pipeline pipe = sg_make_pipeline (&(sg_pipeline_desc) {
            .shader=shd,

            .label="vector drawing",
            .primitive_type=SG_PRIMITIVETYPE_POINTS,
            .layout= {
            .attrs[0].format=SG_VERTEXFORMAT_FLOAT3,
            .attrs[1].format=SG_VERTEXFORMAT_FLOAT4

            }
            });





    // then we will need to pass action within the app 
    sg_pass_action pass_action = {

        .colors[0]= {

            .load_action=SG_LOADACTION_CLEAR,
            .clear_value={0.4f,0.6f,0.5f,0.4f}
            
        }

    };



    while (!glfwWindowShouldClose (window)) {

    int height,width;
    glfwGetFramebufferSize (window,&width,&height);

    sg_begin_pass (&(sg_pass) {
            .swapchain={

             .color_format=SG_PIXELFORMAT_RGBA8,
             .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
             .width=width,
             .height=height,
             .sample_count=1,
             
            },
            .action=pass_action

          

            });
    sg_apply_pipeline (pipe);
    sg_apply_bindings (&(sg_bindings) {
            .vertex_buffers[0]=pointBuffer,
           
            });
   

   



    sg_draw (0,3,2);
    // 9then we end the pass 
    sg_end_pass ();
    sg_commit (); // we are adding this numbers here 
    

glfwSwapBuffers (window);
        glfwPollEvents ();
    }
    sg_shutdown ();

    glfwDestroyWindow (window);
    glfwTerminate ();




}
