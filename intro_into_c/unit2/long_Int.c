 // this file shows me the all infromations about long int value 
 
#include <stdio.h> // becouse i will need the function for input and ouput like printf ()
#include <limits.h> // this header help me to show the maximum of the data type using marcos 

int main () {

//1. find the size of the values of long int on my machine 
printf ("\n THE SIZE OF THE LONG INT ON MY MACHINE IS \n ");
printf ("the size of the long int is %zu \n ",sizeof (long int));


// we find the maximum values my machine can handle from those values 
printf ("\n\n____MAXIMUM OF THE LONG INT  AND MINIMUM VALUES _____ \n");
// those values are unsigned int 

printf ("\nthe maximum of the long int is %li \n",LONG_MAX);
printf ("\nthe minimum of the long int is %ld \n",LONG_MIN);



// now we are going to see how that are stored in the memory block according to thier size 
// i will use 4 numbers to show that 
long int number1=439;
long int number2=88888888;
long int number3=3122232334;
long int number4=9900990939;

// we are going to show them from where now are going to be hidden by os which will give me this space for long int 

printf ("\n\n____MEMORY OCCUPATIONS AND SPACE BETWEEN TWO LONG INT ACCORDING TO THE VALUES\n ");
printf ("the address of number one is %p\n the address of number 2 is %p \n the number of address 3 is %p \n the number of address of number 4 is %p ",&number1,&number2,&number3,&number4);
printf ("\n___LONG INT CONVERTED INTO BINARY AND OCTAL (BASE 8)\n");
// take the given values and then convert them into binary to see how long they will be in the binary as are neing stored in memory 
printf ("\n the number one   :%li\n  in binary: %lb\n  and in octal: %#lo \n",number1,number1,number1);
printf ("\n the number two   :%li\n  in binary: %lb\n  and in octal: %#lo \n",number2,number2,number2);
printf ("\n the number three :%li\n  in binary: %lb\n  and in octal: %#lo \n",number3,number3,number3);
printf ("\n the number fouth :%ld\n  in binary: %lb\n  and in octal: %#lo \n",number4,number4,number4);








}
