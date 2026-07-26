// we are going to write the function which are going with 
#include <stdio.h>

long mult2(long, long );

// the other one for storing the values with in the memorys 
void multstore (long x, long y , long *dest) {

    long t= mult2(x,y);

    // then store this values in the memory 
    *dest= t;

}


// then involke this in meain 

int main () {

    long t;
    multstore (43,34,&t);
    printf ("the multiplications is :%ld\n",t);

}

long mult2 (long x, long y) {

    long s =x*y;
    return s;


} 


