// here we are checking if the pointer size change according to the values it holds 


#include <stdio.h>

int main () {
int a=90;
int *ptr=&a;
printf ("the size of the pointer is :%zu",sizeof (*ptr));

char *name="sam pray";

printf ("the size of the pointer is :%zu \n"\
		,sizeof (*name));

float c=23.4938;
// then we create the pointer which pointes to it 
// the mistake here was to ommit the & to say that the address we store the address and the same time gain the access on it 
// so as shown by this number that size of pointer is dyanmic change based on the datatype 
float *ptr1=&c;
*ptr1=32.90;

printf ("the size of the pointer in float is \
		:%zu\n",sizeof (*ptr1));

// now we are going to check if they have the same valeus of the poiters 
// to estimate what is the storeage they are caputering within my memory 


}
