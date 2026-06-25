// then here we point into the const address of the vaues 
#include <stdio.h>

int main (){
int a=8;
int *const p=&a;
int b=900;



printf ("\nthe address of the values a :%p \n ",p);
// let change the values of the stored in the a
printf ("\n the value of a before changed :%d \n",a);

*p=200;
printf ("\n the values of a changed to :%d",a);

// let try to change the address for which the pinter it was holding
*p=&b;


// they give show the wornning and then i have to type and see what happened 
//
printf("\n the address of p is :%p\n",p);




}
