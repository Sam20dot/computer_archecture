// this function will help us to add the numbers from using only pointer 
// we expect that the cpu will first reload the pointer addressed values into registers and then it values 
// and then it will add them and it will kept the answers in the registers 
// to mean that it will move that in sum and then we except to get the values 
//
//
#include <stdio.h>

int add (int *a ,int *b) {
int j=*a;// in assembly i have to gues it will movl , (%rcx),%rbx
int k=*b; // in assembly i have to gues it will movl (%ecx),%rcx 

int sum =j +k; // addl %rci,%rcs
return sum ; //ret



}


int main () {
int x=9;
int y=89;
int result=add (&x,&y);
printf ("\n result are :%d",result);



}
