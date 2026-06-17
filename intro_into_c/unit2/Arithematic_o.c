// this file contains the althematics operations which are designed for helping the student to understand 
// different things like adding,substracting, dividing and other numbers which could be better for long 
// let writes the co
#include <stdio.h>


int main () {

// tell the user two inter two numbers 
printf ("\n MATHEMATICS ARTHEMATICS TABLES WHICH SHOWS THE NUMBERS AND THIER ALL OPERATIONS \n");
int a ,b;
printf ( "\nenter first number :");
scanf ("%d",&a);

printf ("\nenter second number : ");
scanf ("%d",&b);


// find the sums,difference, multplications and division 
int sum=a+b,sub=a-b,mulply=a*b;
float div =(float)a/(float)b;// here the division can be the floating numbers 

printf ("\nthe sum of a and b :%d\n",sum);
printf ("\nthe dif of a and b :%d\n",sub);
printf ("\nthe mul of a and b :%d\n",mulply);
printf ("\nthe div of a and b :%f\n",div);





}
