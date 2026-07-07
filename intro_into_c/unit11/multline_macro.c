// we are going to use the multline macros
// on the macros multine function or macros it better we dont put the braces on the function 
// and also we dont have to put the any distance between the function and the its definitions 
// this is not allowed 
// SHOW ()  :that space between them are not compile either on the declaration even in calling 
// best options 
// SHOW() : this is the best practice, when we will use the function as macros we use the no space between function 
// name and the function its self 
//
// // other things here is that when we define the function we dont put the praces we put \ on each end of the line 
// to write mult line macros as we did 
//
#include <stdio.h>

#define SHOW(N) \
    printf ("\n we are doing what is good for now !!! \n");

#define SHOWN(N)\
    for (int i=0; i<N; i++ )\
    {\
        printf ("we are here this times :%d\n",i);\
    }


// RANGE FUNCTION WHICH LIVES IN OTHER LANGUAGES LIKE PYTHON IN C 



    






int main () {

SHOW(2);
SHOWN(4);






}
