// we are going to writes the codes which shows the using the datatype and show the following 
// datatype, shifting, conversions, unsigned characters 
// left and right operators 
//
// 
//
// we are going to design the codes which will takes the number and have one number and show us what is means in the char, in integer, and display it in hexadecimals and also in octal and then we can show that as the syttems which can shift that number to the left by two and right by two 
//
#include <stdio.h>



int main (){
unsigned char ch1=32,ch2=43,ch=33;

// shifted left numbers 
//

unsigned char chi=ch1<<2,chii=ch2<<3,chiii=ch<<3;
int num=32;

// then first we show the size of the data using sizeof 
printf ( "\nthe size of the numbers are %lu \n %lu \n %lu \n",sizeof (ch1),sizeof (ch2),sizeof(ch));

printf ("the size of the integer are %lu",sizeof (num));
// then we are going to convert those numbers or charcter in the hexadecimals 
printf ("\nch1 %u is converted into hexadecimla %#x ",ch1,ch1);
printf ("\n the number has %d has converted into the octal %#o ",num,num);

// then we are going to shift thier valus on left and right 
//
printf (" the chars %u\n %u\n  %u\n   has been shifted on the right %u\n %u\n  %u\n  ",ch1,ch2,ch,chi,chii,chiii);
// even the thrity two number must be shifted by just two 
printf ("\nthe even number has been shifted %d\n ",num<<4);

printf ("THIS IS THE END OF THE DAY ONE FOR LERANING MORE ABOUT NEOVIM\n AND C BASICS WHICH I DID NOT REMEMBER\n ");



}
