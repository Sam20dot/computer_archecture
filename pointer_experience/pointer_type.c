// here we are oging to deal with the types of pointesr 
#include <stdio.h>

int main () {
    // when declaring the const values 
    // this values we want to make it constant 
    int a=32;
    const int *p=&a;
    // so now we can not change the values 
    // we can not use the pointer that pointer to assaing the values 

   
    // *p=78;
    // printf ("the values is %d",*p);

    /*
    THE ERROR IS :
    when we used const what we do here lock the address of a using that pointer 
    to mean that,this values is only read or read only locations 
    so that p can not take a new values becouse it points on the consant values 
    */




}