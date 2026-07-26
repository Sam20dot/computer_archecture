#include <GLFW/glfw3.h>
#include <stdio.h>



int main () {
    if (!glfwInit()) {
        printf ("\n glfw has failed to initialize ");
        return -1;

    }
    // so when it initialized well let check if we can get the version 
    printf ("\n the verison of glfw is %s \n", glfwGetVersionString ());

    // then we terminate the glfw which has been initaiized 
    glfwTerminate ();
    return 0;

}