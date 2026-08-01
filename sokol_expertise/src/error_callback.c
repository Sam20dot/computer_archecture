#include "../include/error_callback.h"
#include <stdio.h>

void error_callback (int error ,const char *discription) {
    fprintf (stderr,"error is :%s",discription);
}