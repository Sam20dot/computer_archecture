#define SOKOL_IMPL
#define SOKOL_GLCORE
#include "./libs/sokol/sokol_log.h"
#include "./libs/sokol/sokol_gfx.h"
#include <GLFW/glfw3.h>
#include "./include/error_callback.h"
#include <stdio.h>



int main () {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {

        printf ("failed to initiate the glfw library ");
        return -1;
    }
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window =glfwCreateWindow ( 1200,800,"POLYLAB_EDITOR",NULL,NULL);
    if (!window) {

        printf ("we have failed to create window ");
        return -1;

    }

    // make the window context 
    glfwMakeContextCurrent (window);


    // then we are going to add the things like for sg and for rendering and sending the 
    // data on the screen in the gpu 
    sg_setup (&(sg_desc){


            .environment={
            .defaults={
            .color_format=SG_PIXELFORMAT_RGBA8,
            .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
            .sample_count=1



            }}
            
            });
    printf ("sg_initlized ");
    while (!glfwWindowShouldClose (window)) {
        sg_begin_pass (&(sg_pass) {

                .swapchain ={
                  .height=1000,
                  .width=122,
                  .color_format=SG_PIXELFORMAT_RGBA8,
                  .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
                  .sample_count=1

                },
                .action ={
                .colors[0]={
                  .load_action=SG_LOADACTION_CLEAR,
                
                  
                  .clear_value={0.1f,0.4f,0.5f}
                  
                },
                .colors[1] ={
                .load_action=SG_LOADACTION_CLEAR,
                .clear_value={0.1f,0.8f,0.3f}



                }


                } 
                


                });
        sg_end_pass ();
        sg_commit();
        glfwSwapBuffers (window);
        glfwPollEvents();




        


    }
    sg_shutdown ();
    glfwDestroyWindow (window);
    glfwTerminate ();




    
}

