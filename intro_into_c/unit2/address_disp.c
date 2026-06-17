#include <stdio.h>
#include <limits.h>


// let see how the number are stored in machine 
//
int main () {

int number1=32;
int number2=0x43898;
int num =INT_MAX;

// now i am understanding that os is giving me this range of the numbers on this part !!!! 


// let see if i can see all the values of the int which has been stored the maximum vaues to be 32-bit long 
//
printf (" the address of the maximum number must be almost 32bit \n");
printf (" the address of max is %p",& num	);

printf (" address of the number one is %p \n", &number1);
printf (" address of the number 2 is %p \n", &number2);

printf (" the values in binary are %b\n",number1);
printf ("the values in binary are %b\n ",number2);
// we are going to print the maximum of the numbers 
printf ( " i want to see the maximum of the values in binary to konw exactly how many bits \n");
printf (" the maximum int in the binary is %b\n",INT_MAX);


return 0;


}
