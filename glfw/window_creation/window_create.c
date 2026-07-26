#include <GLFW/glfw3.h>
#include <stdio.h>

// define the call back function to be called 
void error_callback (int error, const char *discription) {
    fprintf (stderr,"the error is :%s \n",discription);

}

int main (void) {

    // first write the function which will handle the error for us
    glfwSetErrorCallback (error_callback) ;
    // second things is to check if glfw has been intialized 
    if (!glfwInit()) {
        printf ("\n the error has been occured ");
        return -1;
    
        
    }
    // then now we are going to create the window 
    GLFWwindow *window =glfwCreateWindow (800,600, "sam_editor",NULL,NULL);
    if (!window) {
        printf ("\n error has been happened in creating window \n");
        return -1;

    }
    


}