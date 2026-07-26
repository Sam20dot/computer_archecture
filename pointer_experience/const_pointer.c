// there are the pointer which can be be assaigned again with any values 
#include <stdio.h>

int main () {
    int a=34;
    int b=324;

    int const *p=&a;
    // we can not assaign any other values on this values
    // *p=&b; this prodide the error for accessing the read only locations 
    // but the pointed values we can use other pointer to point on it 
    int *y=&a;

    // why i can not assaign this values 
    printf ("the pointer values :%d\n",*p);


}