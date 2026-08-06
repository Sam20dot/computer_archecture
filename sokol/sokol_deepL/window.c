#define SOKOL_GLCORE
#define SOKOL_IMPL

#include "../libs/sokol/sokol_gfx.h"
#include "../include/callback.h"
#include <GLFW/glfw3.h>
#include <stdio.h>


// then we can create the all resources all in one structure here abouve 
// so that we can use to make sure that is easier for us 
static struct  {
sg_pipeline pipe;

sg_pass_action pass_action;


}states;




int main () {

    glfwSetErrorCallback (error_callback);
    if (!glfwInit ()) {

        printf ("\n the error in printing the error \n");
        return -1;
    }
    // then defining the hinting for allow the configuration of opengl and other for 3.3 version 
glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

// then create the window 

GLFWwindow *window= glfwCreateWindow (1200,9000, "sam Editor",NULL,NULL);
glfwMakeContextCurrent (window);


// setup and using sokol to render the background color 

sg_setup  (&(sg_desc) {
 
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
        .clear_value= {0.1f,0.4f,0.1f,0.5f}


    }


};
float vertex_buffer[] ={
// position of each vertex
  
    0.1f,0.1f,0.3f

};


// from the book we are about to learn resource creation or resource type 
sg_buffer vbuf=sg_make_buffer (&(sg_buffer_desc) {

        .data=SG_RANGE (vertex_buffer),
        .usage.vertex_buffer=true,
        .usage.dynamic_update=true // to mean that we can update this part 
        

        });


// then we do create the file which can be used for rendering this values 
sg_update_buffer (vbuf,&SG_RANGE(vertex_buffer));
sg_shader shd = sg_make_shader(&(sg_shader_desc){
    // 1. Vertex Shader Source
    .vertex_func.source = 
        "#version 330 core\n"
        "layout(location = 0) in vec3 position;\n"
        "void main() {\n"
        "    gl_Position = vec4(position, 1.0);\n"
        "    gl_PointSize = 10.0;\n" // Sets pixel size of the rendered point
        "}\n",

    // 2. Fragment Shader Source
    .fragment_func.source = 
        "#version 330 core\n"
        "out vec4 frag_color;\n"
        "void main() {\n"
        "    frag_color = vec4(1.0, 0.0, 0.0, 1.0);\n" // Solid red color
        "}\n",

    // 3. Define layout so Sokol knows how inputs match pipeline attributes
   
    .label = "point-shader"
});
sg_pipeline pipe= sg_make_pipeline (& (sg_pipe));


while (!glfwWindowShouldClose (window)) {

    // let first get the heigh and widith of the screen 
    int height,width;

    glfwGetWindowSize (window,&width,&height);


    sg_begin_pass (&(sg_pass) {
            .swapchain={
             .color_format=SG_PIXELFORMAT_RGBA8,
             .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
             .sample_count=1,
             .height=height,
             .width=width
             
  },


            .action=states.pass_action,

            
            });

   
   sg_end_pass ();
   sg_commit ();


    glfwPollEvents ();
    glfwSwapBuffers(window);



}
// systems distroy when we finish to ca:ll all functions inside it
sg_shutdown ();

glfwDestroyWindow (window);
glfwTerminate (); 



}
