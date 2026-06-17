#include <stdio.h>

// this is for shift for right and even on the left 
// we are using unsigned values 
//
int main () {
unsigned char number =-100;
printf (" the corresponding number in 2's complement is %u ", number);

// then we deal with the shift operators 
// on the left as the mulplication and on the right as division 
unsigned char a=32;
unsigned char b=2;
unsigned char f=24;


// then number which has been shifted 
unsigned char c=a<<23;
unsigned char m=b<<2;
unsigned char n=f<<11;

printf (" ----THE FOLLOWING ARE THE NUMBERS WHICH HAS BEEN SHIFTED ON LEFT ");

printf ("\n the number a which is %u has shifted by 23 and it becomes %u ",a,c);
printf ("\n the number b which is %u has shifted by 2 and its becomes %u ",b,m);
printf ("\n the number f which is %u has shifted by 11 and is equal to %u ",f,n);


// those number has been shifted on right part 
unsigned char k=a>>2;
unsigned char j=b>>3;
unsigned char o=c>>8;

printf ("\n the number which has been shifted on right ");

printf ("\n the number a which is %u has been shifted by 2 on right and is %u",a,k);
printf (" \n the number b  which is %u has been shifted by 3 on right now is %u  ",b,j);
printf ("\n the number c which is %u has been shifted by 8 on right and it now %u ",c,o);



}
