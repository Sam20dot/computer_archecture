// we write them with only one line of comment on each part 
#include <GLFW/glfw3.h>
#include <stdio.h>

// error handle call back 
void error_callback (int Error, const char *discrp) {
    fprintf (stderr,"the Error :%s\n",discrp);

}
// main call function 

int main () {
    // init the library to talk to os and other part of machine 
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        printf ("\n there error in initializing lib \n");
        return -1;

    }

    // then hint for setting the opengl to 3 version 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

    // window creation 
    GLFWwindow *window = glfwCreateWindow (1000,800,"sam_editor",NULL,NULL);
    // TEST WINDOW 
    if (!window) {
        printf ("\n error happened in creating window ");
        return -1;


    }
 glfwMakeContextCurrent(window);
    // then now os created the window but we also need to handle this context to 
    // the gpu by making the current context to be current as input on the gpu
    while (!glfwWindowShouldClose(window)) {
       

    }

    // terminate the window first 
    glfwDestroyWindow (window);

    // terminate the window 
    glfwTerminate();

    // this is the second version 


}