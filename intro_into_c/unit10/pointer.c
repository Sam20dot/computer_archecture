// this is the most crusla part within programming which was hard for me to notice before
// we will start with just pointing to a given number 
// which mean that we will store the address of those values and display them on the screen 
#include <stdio.h>



int main (){

int a=10,b=12,c=32,d=49, e=900;

// then now we are going to create the pointer just to point on that values no other things just pointing or storing the values 
int p=&a;
int q=&b;
int n=&c;
int m=&d;
int o=&e; // those store those address let print them on the screen where all are hidden 


printf ("\n__PRINTING THE ADDRESS STORED WITHIN THE STORED VALUES WHICH ARE CALLED POINTER \n BUT THEY DONT HAVE ANY ACCESS ON THAT VALUES \n JUST POINTING ON THEM\n");


printf ("\n the value p located at :%p\n is pointing to a which is located at :%#o\n the value q located at :%p\n is pointing to b which is located at :%#o\n the value n located at :%p\n is pointing to c which is located at :%#o\n the value m located at :%p\n is pointing to d which is located at :%#o\n the value o located at :%p\n is pointing to e which is located at :%#o\n ",&p,p,&q,q,&n,n,&m,m,&o,o);


// now we are going to give access those value which stores address of other values to inter in them and access the data so that they can 
// manipulate them that done by what we call indirection of differencing 
// before we well just storing the address now we are going to access those values from there as follow 
printf ("the value of a is :%d\n",a);
 int *z=&a;
 *z=20;

printf ("the value of b after access to it done by *p :%d\n ",a);







}
