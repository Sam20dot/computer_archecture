// this is the pointer exercises 
#include <stdio.h>


int main () {
int a =19;
printf ("the value of a before changing is :%d",a);
int *z=&a;
*z=23;
printf ("\n the values of a is :%d\n",a);

// there a lot of things which would works better that this 
int r=3,b=4,c=49,e=34;

// then we are going to print all the values using the * asterik as differencing operator 
printf ("\n the values of a is :%d",*(&a));



}
