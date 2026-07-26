// in error handling we need the following 
// in this part so that we can now what happened 
// and they must be initialized before initilized 
//
#include <GLFW/glfw3.h>

// let me first define the function which is call back 
// to mean that they will be called when the error happened 
void error_callback (int error, const char *discription);



int main (void) {
    glfwSetErrorCallback(error_callback);
    // then we can initiate 


}