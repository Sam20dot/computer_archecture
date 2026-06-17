// this is the floating numbers we are going to writes 
//
#include <stdio.h>
#include <limits.h> // for showing us the limits or the final and maximum of each part 
#include <float.h>

int main () {
// the first things how much size they hold 
printf ("_____FLOATING POINTS_____");

printf ("\n the size which will be occupied by floating numbers \n");

// let show them here 
printf ("\nthe size of floating number is                : %zu\n ",sizeof (float));
printf ("\nthe size of double floating number is         : %zu \n",sizeof (double ));
printf ("\nthe size of long double floating number occupy: %zu\n",sizeof (long double));

//2. the size thier final values and minimum values 
printf ("\n the maximum of long double floating number is  :%Lf  min :%Lf \n ",LDBL_MAX,LDBL_MIN);
printf ("\n the maximum of double floating number is       :%lf  min :%lf \n ",DBL_MAX, DBL_MIN);
printf ("\n the maximum of floating number is              :%f   min :%f  \n  ",FLT_MAX,FLT_MIN);

// the second part is to see how this data are being stored within the memory of my machine 

//3 the numbers declarations 
//float 
float number1=32.89;
float number2=3234.90;
float number3=8984.2;

// double numbers 
double number4=8985.9004;
double number5=4343.9093;
double number6=3223.9094;


// long double numbers 
long double number7=7883837.900000;
long double number8=4384793.949484;
long double number9=43233.7898837778;

// how the numbers will be displayed where the os will reserve this numbers in this part 
// float dispay 
printf (" \n the float address1 :%p",&number1);
printf (" \n the float address2 :%p",&number2);
printf (" \n the float address3 :%p",&number3);
// doube display 

printf ("\n the double float address4 :%p", &number4);
printf ("\n the double float address5 :%p",&number5);
printf ("\n the double float address6 :%p", &number6);

// the long double dispaly so that they can look good 


printf("\n the long double float address7 :%p",&number7);
printf("\n the long double float address8 :%p",&number8);
printf("\n the long double float address9 :%p",&number9);


// then we are going to deal with the conversions of this numbers in different things like hexa decimals 
// we will do this for number1 number 4 and number 7 
printf ("\n the long double floating in decimal :%Lf  ",number7);

// float for number 4 
printf ("\n the double floating in decimals     :%lf   ",number4);


//
printf("\n the float in decimal                :%f     ",number1);

// this is the ends of the floating and double numbers from the IEEE

}
