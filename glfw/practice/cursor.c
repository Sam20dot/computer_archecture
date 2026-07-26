#include "cursor.h"
#include <stdio.h>

void cursor_position_callback (GLFWwindow *window,double px,double py){

    printf (" y_position:%lf\n x_position:%lf\n",py,px);
    fflush (stdout);

}