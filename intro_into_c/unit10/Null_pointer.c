
// when the pointer i not well initialized or firt it have to be initialzied on zero so that it can help us 
// to prevent to point to a gabage or unknow things 
#include <stdio.h>


int main () {

typedef int ptr_t;
ptr_t *ptr1;
ptr_t *ptr2=NULL;

// then we check the ouput 

printf ("\n the values of pointer one is :%p \n is pointing to :%d",ptr1,*ptr1);
printf ("\n the values of pointer two is :%p \n is pointing to :%d",ptr2,*ptr2);



}
