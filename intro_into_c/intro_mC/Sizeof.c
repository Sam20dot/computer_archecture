#include <stdio.h>



int main () {

// now we are going to use Sizeof to see the bytes occupied by the data type in the c programming 
// most of the time char is about 1 byte
// int 4 byte and even long long int can be around 8byte of the memory so let test that in real world 
//
int num=21;
char ch='A';
float numF=78.8;
// the mistakes i have used the capital letter instead of the short one 

printf ("the size of the numbers are %ld",sizeof(num));
printf (" the size of a char is %ld ", sizeof (ch));



}
