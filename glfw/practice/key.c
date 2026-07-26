#include "key.h"
#include <stdio.h>


void key_callback (GLFWwindow *window, int key , int scancode,int action, int modes) {
    if (key==GLFW_KEY_E && action==GLFW_PRESS) {
        printf ("the key has been pressed :%d\n and code is :%d\n the actual letter is :%c",key,scancode,key);
        fflush(stdout);


    }
}