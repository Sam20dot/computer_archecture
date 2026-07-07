#include <stdio.h>



#define  DELTA(a,b,c)  ((b)*(b)-4*a*c) // there must be no space between name of macros and its declaration  

// then we are going to use that in the main function 
int main () {
 
    printf ("\n the deleta of the following numbers are :%d",DELTA(21,43,5));

    // the delat of the following number is zero let test that 
    printf ("\n the delta of this numbers are zero a=2, b=4, c=2 :%d",DELTA (2,4,2));



}
