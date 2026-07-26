#include <stdio.h>


int main () {
    int a=90;
    int *b=&a;
    printf ("\n this is the pointer values %d ",*b);
    printf ("\n the size of pointer %zu \n", sizeof (b));
    printf ("\n the address of the values is %p",b);
    printf ("\n the address of the values is %p",&a);



}