#include <GLFW/glfw3.h>
#include <stdio.h>
#include "errorhandle.h"
//#include "key.h"
#include "char.h"
#include "cursor.h"
#include "mouse_button.h"
#include "scollor.h"






int main () {
    glfwSetErrorCallback(error_callback);
    // then initiate the glfw framework
    if (!glfwInit()) {
        printf ("it failed to initialize the library");
        return -1;


    }
    // config the hint so that we will make sure we have all requirements 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
        // create window 
    GLFWwindow *window=glfwCreateWindow (1200,800,"sam_editor",NULL,NULL);
    // check if window created 
    if (!window) {
        printf (" window failed to load or created !");
        return -1;

    }
    // then we have all needed let handle this and notify gpu graphic apis to draw 
    glfwMakeContextCurrent (window);

    // then we register the key events 

    //glfwSetKeyCallback (window, key_callback);
// char register 

   //glfwSetCharCallback(window,char_callback);
   //glfwSetCursorPosCallback(window,cursor_position_callback);

   //glfwSetMouseButtonCallback(window,mouse_callback);

   // scollor 
   glfwSetScrollCallback(window,scoll_callback);
   




    // then keep window open unless we press any key for terminations 
    while (!glfwWindowShouldClose(window)) {
        glfwWaitEvents();
    }

    // then terminate the app and see first 
    glfwDestroyWindow (window);
    glfwTerminate();
    return 0;





}