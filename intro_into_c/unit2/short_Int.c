// we are going to deal with the short integer 
// we have to have four section where all the things must be shown 

#include <stdio.h>
#include <limits.h>


int main () {

	printf ("\n \nTHIS IS ALL ABOUT SHORT INT WHITH ALL ALL INFROMATIONS FROM THIS CODES \n ");
	

// section one to show the maximum values of short int 
//
printf ("---MAXIMUM AND MINIMUM VALUES ARE THE FOLLOWING ------");
printf ("\nthe maximum values is %hi  ",SHRT_MIN);
printf ("\nthe minimum values is  %hi \n ",SHRT_MAX);


// THE SECTION TWO WHERE WE ARE GOINT TO SEE HOW THOSE ARE ARRANGED IN MEMORY 

short int number1=32;
short number2=33;
short int number3=89;
short int number4=32;
short int number5=77;


// then we are going to print that to see what will heppen on the sqeunce of tha last numbers 
printf ("---THE ADDRESS MUST DIFFER BY TWO BYTE BECOUSE THE SHORT INT IS ONLY 16 BIT \n");
printf("\n the address of number1 is %p\n the address of number 2 is %p\n the address of number3 is %p \n the address of number4 is  %p \n the address of number 5 is %p\n  ",&number1,&number2,&number3,&number4,&number5);

// then we are going to convert those numbers into binary to see how long they are 
printf ("--- CONVESION OF THE NUMBER GIVEN INTO BITS ------");

printf ("\n the bits of first number are %b \n the bits of the second numbers are %b \n the bits of the third numbers are %b \n the bits of the fourth numbers are %b \n the the bits of the last numbers are %b \n",number1,number2,number3,number3,number5);

// then we are going to perform shifts where we can see that even in binary
printf ("\n the first number is shifted %b\n the second number is shifted %b\n the third number is shifted%b \n the fouth number is shifted %b \n the fitth number is shifted %b",number1<<2,number2>>2, number3<<3,number4>>4,number5>>5);


// then we are going to test what we call tranaction error of the number which are beyond the the binary part 
short int beyond_1=32769;
short int beyond_2=40000;
short int beyond_3=-40000;


// let see what will remain
printf(" \n--THIS SECTION SHOWS THE PART HOW THE NUMBER CORRUPTS WHEN THEY ARE BEYOND ");
printf ("\nthe beyond number 1 is %hi \n the number again which is beyond is %hi \n the number which is beyond is %hi \n", beyond_1,beyond_2,beyond_3);






}
