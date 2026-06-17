// type conversion refers process of changing the data type of the values based on the data type used for declaration
// example if the values is declaraed as int and we have the part which is float part we will at compilling time remove the decimals parts and remain with the whole numbers 
//
// example is that if we have the other datatype which declare on the flaoat  the values will be auto converted into floating number to help the calculations 
// this is what we call TYPE CONVESION TYPE 1 IMPRICITLY 
//
// EXAMPLE :
#include <stdio.h>


int main (){

float number1=89; // this number is int but will be converted into the float 

int number2 =21.4333;// those decimals will be removed 
printf ("\n the first number has been changed into float as it was int :%f",number1);
printf ("\n the second number has been chanegd into int as it was float: %d\n",number2);



}
