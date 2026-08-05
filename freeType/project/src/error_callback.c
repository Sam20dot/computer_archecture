#include "../includes/error_callback.h"
#include <stdio.h>


void error_callback (int Error,  const char *discription) {

fprintf (stderr,"the Error:%s",discription);



}
