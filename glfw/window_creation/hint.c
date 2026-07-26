// we are dealing with hint which are run before deal with other things 
#include <GLFW/glfw3.h>
#include <stdio.h>

// error handling functions 
void error_callback (int Error, const char* discription) {
    fprintf (stderr,"\n the error :%s",discription);

}

// in main function
int main () {
    // first we initiate
    if (!glfwInit ()) {
        printf ("\n the window did not initialized ") ;
        return -1;

    }

    // then handle the error part 
    glfwSetErrorCallback (error_callback);
    // then we set the hind before creating the window 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwContextHint(GLFW_CONTEXT_VERSION_MINOR,3);

    // then now we can create the window 
    GLFWwindow *window =glfwCreateWindow (600,800,"sam_editor",NULL,NULL);

// then window are not nessery we distory it 
GLFWTerminate(window);
return 0;


}

