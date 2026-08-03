// now after we create the window infomation we have to handle them on the 
// gpu to do its magics 
#include <GLFW/glfw3.h>
#include <stdio.h>

void error_callback (int Error,const char * discrp) {
    fprintf (stderr, "the error happen :%s",discrp);

}

int main () {
    glfwSetErrorCallback(error_callback);

    //init 
    if (!glfwInit ()) {
        printf ("the error happened ");
        return -1;

    }
    // hints which can be used before we create the window 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

    // window 
    GLFWwindow *window =glfwCreateWindow(600,800,"sam_editor",NULL,NULL);
    if (!window) {
        printf ("the window did not initialzed !!\n");

    }

    // we handle the context or meaning to the GPU driver so that it can know what to do
    while (!glfwWindowShouldClose(window)){
        glfwMakeContextCurrent (window);
   

    } 
    


    // then termiate the window 
    glfwDestroyWindow(window);

    // then we also remove all initialization which has been remained due to 
    // the initialized of glfwInit()
    glfwTerminate();

    
    return 1;




}
