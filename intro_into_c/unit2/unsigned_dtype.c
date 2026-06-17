// then here we are going to combine the part of the unsigned data types we will write the different blocks so let start 
//
#include <stdio.h>
#include <limits.h>


int main () {

// part1 
printf ("___ THE SIZE OF EACH UNSIGNED DATA TYPE ____n\n");


printf ("\n the size of unsigned char is      :%zu\n",sizeof (unsigned char));
printf ("\n the size of unsigned short int is :%zu\n", sizeof (unsigned short int));
printf ("\n the size of unsigned int is       :%zu\n", sizeof (unsigned int ));
printf ("\n the size of unsinged long int     :%zu\n",sizeof (unsigned long int ));
printf ("\n the size of unsinged long long int:%zu\n",sizeof (unsigned long long int ));


// the next part is to writes the maximum and minum of thier values 
printf("\n_____ THE SIZE OF THE EVERY PART HERE SHOWING BY AS IT START FROM ZERO TO THAT VALUES _____\n");
printf ("\n the max and min of unsigned char is      :%u     ",UCHAR_MAX);// min macros is not available on each part 
printf ("\n the max and min of unsigned short int    :%hu ",USHRT_MAX);
printf ("\n the max and min of unsigned int          :%u",UINT_MAX);
printf ("\n the max and min of unsigned long int     :%lu",ULONG_MAX);
printf ("\n the max and min of unsigned long long int:%llu ",ULLONG_MAX);



// the third part for showing the part where to convert one number on each in two up to binary and hexa decimals and shitf 
unsigned char ch =48;
unsigned short int number1=267;
unsigned int number2=213;
unsigned long int number3=90000;
unsigned long long int number4=2888888888;
// now we are going to display those numbers in other so that maybe look good in three formats for each part 
printf ("\nthe unsigned long long int in decimal is :%llu \n in hex :%#llx \n in binary :%#llb",number4,number4,number4);
printf ("\nthe unsigned long int in decimal is      :%lu \n  in hex :%#lx \n  in binary :%#lb",number3,number3,number3);
printf ("\nthe unsigned ing in decimal              :%u  \n in hex  :%#x  \n in binary  :%#b",number2,number2,number2);
printf ("\nthe unsinged short int in decimal        :%hu \n in hex  :%#x   \n in binary :%#b",number1,number1,number1);
printf ("\nthe unsigned char in in decimal :%u \n in hex :%#x in binary :%#b \n",ch,ch,ch);








}
