// this is the function pointer which can be used for 
// showing how we access the or point to the function back 
#include<stdio.h>

void funct () {
    printf ("\n inside my function ");

}

int main () {
    int a=9;
    int b[3]={2,1,4};

    printf (" the address of the values a is :%p\n ",&a);
    printf ("\n the address of b array is :%p \n",&b);
    printf ("\n the address of my funct is :%p\n",funct);
    printf ("\n the address of function is :%p\n",&funct);
    

}