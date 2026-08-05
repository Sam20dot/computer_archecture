#include <GLFW/glfw3.h>
#include <stdio.h>

//#define SOKOL_IMPL
#//define SOKOL_GLCORE
//#include "./libs/sokol/sokol_gfx.h"
#include "./include/callback.h"




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
while (!glfwWindowShouldClose (window)) {

    glfwPollEvents ();


}
// systems distroy when we finish to ca:ll all functions inside it 
glfwDestroyWindow (window);
glfwTerminate (); 



}
