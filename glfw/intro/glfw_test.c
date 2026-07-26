#include <GLFW/glfw3.h>
#include <stdio.h>



int main (void) {
    if (!glfwInit()) {

        printf ("we have failed to start the glfw \n");
        return -1;

    }
    printf ("the version of glfw is :%s\n",glfwGetVersionString ());
    glfwTerminate();
    return 0;







}
