
#define SOKOL_IMPL
#define SOKOL_GLCORE
#include "./libs/sokol/sokol_gfx.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "./includes/error_callback.h"


// then we create the stucture for the states 
static  struct {
    sg_pipeline pipe;
    sg_pass_action pass_action;
}states;



int main () {


    glfwSetErrorCallback (error_callback);
    if (!glfwInit ()) {

        printf ("failed to initlize the glfw library:");
    }


    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window =glfwCreateWindow (1999,800, "sam editor",NULL,NULL);



    if (!window) {

        printf ("failed to render or creating the window ");
        return -1;
    }
    glfwMakeContextCurrent (window);
    sg_setup (&(sg_desc) {
            .environment= {

              .defaults= { 
                .color_format=SG_PIXELFORMAT_RGBA8,
                .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
                .sample_count=1

            }
            }
        
            });
    states.pass_action=(sg_pass_action) {
        .colors[0]={

            .load_action=SG_LOADACTION_CLEAR,
            .clear_value= {0.34f,0.43f,0.3f,0.9f}
            
        }



    };
while (!glfwWindowShouldClose(window)) {
    int height,width;
   glfwGetWindowSize (window ,&width,&height);



    sg_begin_pass (&(sg_pass) {
            .swapchain = {
              .color_format=SG_PIXELFORMAT_RGBA8,
              .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
              .sample_count=1,
              .width=width,
              .height=height

              

            },
            .action=states.pass_action,


            });
    sg_end_pass ();
    sg_commit ();

 glfwSwapBuffers (window);
 glfwPollEvents ();



}
sg_shutdown ();
glfwDestroyWindow (window);
glfwTerminate ();






}


