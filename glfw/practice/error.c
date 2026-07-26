#include "errorhandle.h"
#include <stdio.h>


void error_callback (int error, const char  *discription) {
    fprintf (stderr,"the error is :%s",discription);

}