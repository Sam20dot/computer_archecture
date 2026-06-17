// this file contains the hex_decimal numbers and octal number convestiona nd how they are being 
// displayed within the integers from the different formats 
#include <stdio.h>


int main(){

int hex=0xff;
int bin=0b110;
int octal=012;
int decimal=32;


// then we are going to display that numbers on the screen and to see if the int will show them 
// as they are in int
printf ("-- THE NUMBER TO BE SHOWN ON THE SCREEN \n");
printf (" the number is now converted %d, %d,%d,%d\n",hex,bin,octal,decimal);

printf ("hex_decimal showing \n");

printf ("the hexa decimals are %x,%x, %x , %x :\n",hex,bin,octal,decimal);
return 0;




}
