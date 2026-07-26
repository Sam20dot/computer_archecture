// we are designing the editor this is the first part which will be used for handling simple things 
#include <GLFW/glfw3.h>
#include <stdio.h>


// then we define the error handling next it will be in the other file 
void error_callback (int Error, const char * discription) {
    fprintf (stderr,"error :%s",discription);

}

int main () {
    // first handle all error which can be found 
    glfwSetErrorCallback(error_callback) ;
    // init
    if (!glfwInit()) {
        printf ("the error happened ");
         return -1;

    }
    // put the hint 
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    // create window 
    GLFWwindow *window=glfwCreateWindow (1200,800,"sam_editor",glfwGetPrimaryMonitor(),NULL);
    

    // check if it has been created 
    if (!window ) {
        printf ("\n window did not created ");
        return -1;

    }
                                                          // then use create the context part 
    glfwMakeContextCurrent (window);

    // keep up open 
    while (!glfwWindowShouldClose(window)) {
        glfwWaitEvents();                                 // this is advanced than using glfwPollEvent() 
                                                          // it update only when the event happen 
    } 
    //after we terminate the window it will be removed 
    glfwDestroyWindow(window);

    // finish init 
    glfwTerminate();


}

