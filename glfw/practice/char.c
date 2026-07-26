#pragma once 
#include "char.h"


void char_callback (GLFWwindow *window,unsigned int codeprint ) {
    fprintf ("the pressed char is :%c and its code is :%d",(char)codeprint,codeprint);
    
}
