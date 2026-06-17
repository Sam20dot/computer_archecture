// in shift operator we have two types one is for right shift operator >> 
// and the left shift operator >> 
/*LEFT SHIFT OPERATOR :
 * on the left shift we add the zeros on the last of the number and 
 *on the this part when we shift one size like multiplying by two 
 example if i had like 5 and shift it by two on the left it will be like mulplying with 4 becouse is 
 2power 2 
 as will be indicated in the following files 
 *
 *
 *
 *
 * */

#include <stdio.h>


int main (){

// on this example we will use the part which will char which will show how that works 
unsigned char a=4,b=54,c=25;

// then we shift them using the shift operator 
unsigned char d=a<<2;
unsigned char e =b<<3;
unsigned char f=c<<3;




// we are going to see if the numbers will be shifted 
//

printf ("the number to be shown here are are demostrating the shifting in left \n ");
printf ("\nthe number a %u are shifted are %u",a,d);
printf ("\nthe number b %u has shifted to %u ",b,e);
printf ("\nthe number c %u has shifted to %u ",c,f);
printf (" \nthe above numbers has been designed for showing how shift works but for the left shift \n");








}
