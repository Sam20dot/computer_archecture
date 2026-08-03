// then we add sokol 
#define SOKOL_IMPL
#define SOKOL_GLCORE

#include "./libs/sokol/sokol_gfx.h"
#include "./libs/sokol/sokol_log.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "./include/error_callback.h"



int main () {

    glfwSetErrorCallback (error_callback) ;
    if (!glfwInit ()) {

        printf ("\n failed to initlize");
        return -1;
    }
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    // create window 
    GLFWwindow *window =glfwCreateWindow (1500,1000, "PolyLab editor",NULL, NULL);
    if (!window) {

        printf ("\n window has been failed to be created ");
        return -1;


    }
    printf ("\n window created !!!");

    // then we make the context current 
    glfwMakeContextCurrent (window);

    // then we initilize the sg library 
    sg_setup (&(sg_desc) {

            .environment= {
             .defaults= {
               .color_format=SG_PIXELFORMAT_RGBA8,
               .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,

               
             }
             
            },
            .logger={
             .func =slog_func
             

            }
        
            });
    printf ("\n sokol has been initilized !!! \n");

    while (!glfwWindowShouldClose(window))
{
    sg_begin_pass(&(sg_pass){

        .swapchain = {
            .width = 1500,
            .height = 1000,
            .sample_count = 1,

            .color_format = SG_PIXELFORMAT_RGBA8,
            .depth_format = SG_PIXELFORMAT_DEPTH_STENCIL,

            .gl.framebuffer = 0
        },

        .action = {
            .colors[0] = {
                .load_action = SG_LOADACTION_CLEAR,
                .clear_value = {
                    0.2f,
                    0.2f,
                    0.3f,
                    1.0f
                }
            }
        }
    });


    sg_end_pass();
    sg_commit();

    glfwSwapBuffers(window);
    glfwPollEvents();
} 


   
    sg_shutdown ();

glfwDestroyWindow (window);
glfwTerminate ();

}

