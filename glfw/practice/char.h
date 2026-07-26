#pragma once
#include <GLFW/glfw3.h>
#include "char.h"
#include <stdio.h>

void char_callback (GLFWwindow *window,unsigned int codeprint ) {
    printf ("%c",(char)codeprint);
    fflush(stdout);


}
