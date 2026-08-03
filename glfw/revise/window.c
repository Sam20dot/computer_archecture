#include <GLFW/glfw3.h>
#include <stdio.h>


void error_callback (int error , const char *discription) {

    fprintf (stderr,"the error is :%s",discription);

}

int main (void ) {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        printf ("the glfw gailed to load");
        return -1;

    }

    // then we set the hints 
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // then we create the window 
GLFWwindow *window= glfwCreateWindow(1200,800,"SAM EDITOR ",NULL,NULL) ;
if (!window) {
    printf ("the weindow did not been created !!!");
    return -1;

}
// we are learning      we make the window current context 
glfwMakeContextCurrent (window);
while (!glfwWindowShouldClose (window)) {
    glfwWaitEvents();




}

glfwDestroyWindow(window);
glfwTerminate();



}
