#include "../include/text_render.h"




void error_callback(int Error,const char * discritpion) {


    fprintf (stderr,"the error number is :%d and discrition :%s\n",Error,discritpion);


}
int initilize_glfw () {

    glfwSetErrorCallback (error_callback);
      if (!glfwInit()) {

        printf ("\n the library failed to load ");
        return -1;

    }

    // then set the hints 
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  

    return 1;

}

GLFWwindow *create_window (char * windowName) {
    GLFWwindow *window = glfwCreateWindow (1000,800,windowName,NULL,NULL);
    if (!window) {

        printf ("failed to print the window or make the window \n");
        return NULL;
        

    }
    glfwMakeContextCurrent(window);
    return window;


}
int close_window (GLFWwindow* window) {

    glfwDestroyWindow (window);
    glfwTerminate ();
    return 1;



}


