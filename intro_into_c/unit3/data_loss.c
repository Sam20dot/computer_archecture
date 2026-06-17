/*
 * DATA LOSS OCCURS WHEN WE ARE MOVING FROM THE HIGHER ORDER INTO LOWER ORDER :
 * example we can convert the infromation from the higher order like int into char here the data could lost 
 * as it will be demostrated becouse char it occupys only 8 bit so the information which are beyond in that part will be lost 
 * to mean that what could be better is to have to move from lower to higher from example from 
 * char---> int 
 * int ---> long int 
 * long int ---> long long int 
 *
 *
 * we can also convert that from the float into the double 
 * the below there is an example for doing that 
 *
 * */
#include <stdio.h>



int main () {

// infromation we gonna make them lost ;
int b=0B011111100000000;
char c=b; // almost all infromation has been storen or losted 
	  
printf ("\n the lost of the infromations ___\n");
printf ("\n the b values :%d",b);
// the lost data 
printf ("\n the c values are %d\n",c);



// but it was the from low to higher oerder the info will remain the same 
int b1=0b000000000111101;
long int c1=b1;

printf ("\nthe values now will never lost\n ");
printf ("\n the value of b in decimal :%d",b1);
printf("\n the value of c in decimal is :%ld\n ",c1);



return 0;



}
