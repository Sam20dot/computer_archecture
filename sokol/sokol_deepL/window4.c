#define SOKOL_IMPL
#define SOKOL_GLCORE

#include"../libs/sokol/sokol_gfx.h"
#include "../libs/sokol/sokol_log.h"
#include "./include/callback.h"



// then glfw 
#include <GLFW/glfw3.h>
#include <stdio.h>

int main  () {

    // then first we have to set the glfw 
    glfwSetErrorCallback (error_callback);

    if (!glfwInit ()) {

        printf ("there is error for starting glfw library");
        return -1;
        


    }
    
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    // WINDOW Part 
    GLFWwindow* window = glfwCreateWindow (1200,800,"SAM_EDITOR", NULL,NULL);

    if (!window) {

        printf (" window has been failed to load");
        return -1;

    }

    glfwMakeContextCurrent (window);

    // we introduce sokol within in the codes 
    sg_setup (& (sg_desc) {

            .environment= {

             .defaults= {
               .color_format= SG_PIXELFORMAT_RGBA8,
               .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
               .sample_count=1,

              }
           
            },

             
               .logger.func = slog_func,
            });
    float buffer[]={

        // buffer contains many things like points and colors and they are 
        // sorted on the different shaders stages 
        // position                color 
        -0.9f,0.3f,0.4f,           0.1f,0.3f,0.4f,0.4f
    };



    // then we are going to add the resources which is buffers 
    sg_buffer vbuf=sg_make_buffer (&(sg_buffer_desc) {
            .usage.vertex_buffer=true,
            
            .data=SG_RANGE(buffer)


            });


    // then we create the pipeline as the rules which will make the whole things 
// shaders for one point 
    sg_shader shd=sg_make_shader (& (sg_shader_desc) {
            .label="points on the screen",
            .vertex_func.source=
            "#version 330 core \n"
            "layout (location=0) in vec3 a_pos;\n"
            "void main () { \n"
            "gl_Position=vec4(a_pos,1.0) ;\n"
            "gl_PointSize=100.0;\n"
            "}",
            .fragment_func.source=
            "#version 330 core \n"
            "out vec4 FragColor;\n"
            "void main () {\n"
            " FragColor=vec4(0.3f,0.8f,0.9f,1.0f) ;\n"
            "}\n"
            ,
            .attrs[0].glsl_name="a_pos"



            });
    
    // then we desgn for passing actions
    sg_pipeline pipe= sg_make_pipeline  (&(sg_pipeline_desc) {

            .shader=shd,
            .layout= {

            .attrs[0].format=SG_VERTEXFORMAT_FLOAT3
            }
            ,
            .primitive_type=SG_PRIMITIVETYPE_POINTS,


            });

    sg_pass_action pass_action= {

        .colors[0] ={

            .load_action=SG_LOADACTION_CLEAR,
            .clear_value= {0.1f,0.3f,0.4f,0.4f}

        }
        

    };


    // then let start the main loop to listen to the window 
    while (!glfwWindowShouldClose (window)) {

        // then we start to pass the background color but after getting 
        // the intire screen 
        int width,height;

        glfwGetFramebufferSize(window,&width,&height);
        sg_begin_pass (&(sg_pass){

                .swapchain = {

                .color_format=SG_PIXELFORMAT_RGBA8,
                .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
                .width=width,
                .height=height,
                .sample_count=1,
                .gl.framebuffer=0
                
                },
                

                .action=pass_action

                });
        sg_apply_pipeline (pipe);
        sg_apply_bindings (&(sg_bindings) {

                .vertex_buffers[0]=vbuf
                });
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

