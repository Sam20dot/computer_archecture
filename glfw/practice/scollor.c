#include "scollor.h"
#include <stdio.h>


void scoll_callback (GLFWwindow *window , double xoffset, double yoffset) {
    printf ("yoffset:%lf\nxoffset:%lf\n",yoffset,xoffset);
    fflush(stdout);

}