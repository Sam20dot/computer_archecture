#include <stdio.h> // becouse i will need to print something on the terminal so i use this function which tell os to do that                    through that we call ABI (application binary interface )
#include <limits.h> // i use it becouse i want to know the final limits of long and long int for the values i am going to us                     e  also they provides micros which replaced in compiling time for exactly values wo that i can see that 


int main () {

// part one to show the size of byte it occupy in my machine 
printf ("\n\n__LONG LONG INT IT HOLD THE FOLLOWING BYTE IN MEMORY__\n\n");

printf ("\n the size of the long long  int is %zu",sizeof (long long int));


//locatoins arranged within my machine according to the different in size and long long int and memory arrangement in 8-bit registers 
long long int number1=900000000003;
long long int number2=93039393939393378;
long long int number3=75799993938393889;
long long     number4=43434343233950999;

// then we are going to find the place where all of them are being stored !!!! 

printf ("\n__ WHERE LONG INT IS HIDING AND HOW MUCH ONE NUMBER IS HOLDING AND SPACE BETWEEN\n AND ANATHER _____\n");
printf ("the address of number one :%lld is %p:\n the address of number two :%lli is %p:\n the address of number three :%lld is %p:\n the address of the number fouth :%lld is %p:\n ",number1,&number1,number2,&number2,number3,&number3,number4,&number4);


// then now we are going to convert those numbers into different formats like binary, hexa decimals and also octal with 
// the infrocement of the actual show like 0x for hex 0b for binary and 0 for octal 

printf("the number 1 is :%lld \n in binary is :%#llb \n in octal :%#llo \n in hex :%#llx \n ",number1,number1,number1,number1);
printf("the number 2 is :%lld \n in binary is :%#llb \n in octal :%#llo \n in hex :%#llx \n ",number2,number2,number2,number2);
printf("the number 3 is :%lld \n in binary is :%#llb \n in octal :%#llo \n in hex :%#llx \n ",number3,number3,number3,number3);
printf("the number 4 is :%lli \n in binary is :%#llb \n in octal :%#llo \n in hex :%#llx \n ",number4,number4,number4,number4);

// the last question is what happen when we exceed the limits of the values like this 
long long int beyond_1=2333333333333;
long long int beyond_2=beyond_1>>4;

printf ("\n the beyond of the long long it is the following \n");
printf (" the long int here is :%lld\n and has shifted by 4 on right :%lld \n",beyond_1,beyond_2);




}
