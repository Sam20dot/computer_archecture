// the size of the pointers and how they store the valuues 
#include <stdio.h>



int main () {

int a=89;
int *ptr1=&a;
int b=21;
int *ptr2=&b;
int c=32;
int *ptr3=&c;
int d=900;
int *ptr4=&d;


// then we are going to print the address of each values here from a to d
//
printf ("\n THIS VALUES SHOWS THE ADDRESS AND THE VALUES OF VARIBLES \n");
printf ("\nthe address of a is :%p\n values of a is :%d",&a,a);
printf ("\nthe address of b is :%p\n values of b is :%d",&b,b);
printf ("\nthe address of c is :%p\n values of c is :%d",&c,c);
printf ("\nthe address of d is :%p\n values of d is :%d",&d,d);

// now we are going to print the address of the pointers and size 
printf ("\n\n\n THIS TABLE SHOWS ADDRESS OF POINTER ,SIZE , THE VALUES THEY STORED AS THE ADDRESS \n OF VALEUS FROM A\n \n  ");


printf ("\n the address of pointer 1 :%p\n size of pointer1:%zu \n the values of ptr1 is :%p",&(ptr1),sizeof (ptr1),ptr1);
printf ("\n the address of pointer 2 :%p\n size of pointer2:%zu \n the values of ptr2 is :%p ",&(ptr2),sizeof (ptr2),ptr2);
printf ("\n the address of pointer 3 :%p\n size of pointer3:%zu \n the values of ptr3 is :%p ",&(ptr3),sizeof (ptr3),ptr3);
printf ("\n the address of pointer 4 :%p\n size of pointer4:%zu \n the values of ptr4 is :%p ",&(ptr4),sizeof (ptr4),ptr4);

printf ("\n\n\n THE ADDRESS OF WHICH POINTS BACK TO ACTUAL VALUES FROM THE POINTER WITH HELP OF * \n WHICH POINT EXACTLY TO ACTUAL VALUES \n STORED IN THAT PLACE \n \n ");


// then now we are going to deal with the part of astlites part which is the access of them 

// those are values which are accessing the values in as the acual data from that data 
printf ("\n the address of actual pointed_a :%p\n size of pointer_v1:%zu \n the values of ptr_a:%d\n",&(*ptr1), sizeof (*ptr1),*ptr1);
printf ("\n the address of actual pointed_b :%p\n size of pointer_v2:%zu \n the values of ptr_b:%d\n",&(*ptr2), sizeof (*ptr2),*ptr2);
printf ("\n the address of actual pointed_c :%p\n size of pointer_v3:%zu \n the values of ptr_c:%d\n",&(*ptr3), sizeof (*ptr3),*ptr3);
printf ("\n the address of actual pointed_d :%p\n size of pointer_v4:%zu \n the values of ptr_d:%d\n",&(*ptr4), sizeof (*ptr4),*ptr4);




}
