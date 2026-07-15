// this file contains the codes which will tell the compiler to compile the codes when pi is defined 
#include <stdio.h>


#define PI 3.14


int main (){


   #ifdef PI
    printf (" the pi is defined and is :%f",PI);
   #endif


}
