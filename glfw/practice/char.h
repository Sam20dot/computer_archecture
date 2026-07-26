#pragma once
#include <GLFW/glfw3.h>
#include "char.h"
#include <stdio.h>

void char_callback (GLFWwindow *window,unsigned int codeprint ) {
    printf ("the pressed char is :%c and its code is :%d",(char)codeprint,codeprint);
    fflush(stdout);
    

}
