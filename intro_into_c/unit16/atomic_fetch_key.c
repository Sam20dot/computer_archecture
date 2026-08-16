#include <stdio.h>
#include <stdatomic.h>
#include <stdbool.h>



int main () {

    // here we are about to use the values which are here  atomic_fetch_key.c
    atomic_int a=90;
    _Atomic unsigned char b=0b0001;

    // and then we use it with all use case 
    // we start with key which is add
    int original= atomic_fetch_add (&a,90);
    printf ("the original values is :%d \n the changed values is :%d\n",original,a);


    int subStract=atomic_fetch_sub (&a,788);
    printf ("the original values is :%d \n the changed values is :%d\n",subStract,a);


    // then bitwise operators like or,xor, and and 
    _Atomic unsigned char original_one=atomic_fetch_xor (&b,0b0000);
    
    printf ("the original values is :%d \n the changed values is :%d\n",original_one,b);


    _Atomic unsigned char original_and=atomic_fetch_and (&b,0b0011);
    
    printf ("the original values is :%d \n the changed values is :%d\n",original_and,b);

    _Atomic unsigned char original_or=atomic_fetch_or   (&b,0b00111);

    // then we are about to display the following 
    printf ("the original values is :%d \n the changed values is :%d\n",original_or,b);













}
