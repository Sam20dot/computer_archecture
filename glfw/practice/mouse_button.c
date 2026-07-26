#include "mouse_button.h"



void mouse_callback (GLFWwindow *window, int button,int action,int modes) {
    //printf ("the mouse button clicked :%d\n action:%d \n",button,action);
    if (action==GLFW_PRESS) {
        printf ("button %d pressed \n",button);

    }
    else if (action==GLFW_RELEASE) {
        printf ("the button %d is released \n",button);


    }
    fflush(stdout);

}