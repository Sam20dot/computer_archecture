// this is for dividing number which are int and converted into double or other numbers 

#include <stdio.h>



int main () {

double a=98/11;
printf ("\n the number is :%lf\n",a);

// also how the char with int can be converted 
printf("\n how har will be converted into int \n") ;

int b=100;
char ch1= 'a';

int sum;
sum = b+ch1; // char will be convered into a which is 63;


printf ("the sum is :%d\n",sum);
printf ("\n the char is :%d and \n %c",ch1,ch1);


}
