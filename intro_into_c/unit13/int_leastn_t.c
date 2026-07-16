// we are going to write the codes which will help us to explore the atleast usages 


#include <stdio.h>
#include <inttypes.h>




int main () {
// declarations 
 
    int_least8_t           a;
    int_least16_t          b;
    int_least32_t          c;
    int_least64_t          d;

// ask user for input the codes 

    printf ("\nenter at least  8-bit number :");
    scanf ("%"SCNdLEAST8"",&a);
    printf ("\nenter at least 16-bit number :");
    scanf ("%"SCNdLEAST16"",&b);
    printf ("\nenter at least 32-bit number :");
    scanf ("%"SCNdLEAST32"",&c);
    printf ("\nenter at least 64-bit number :");
    scanf ("%"SCNdLEAST64"",&d);


    // display that on the screen by using printf and  as the library function which uses the stdout as system call
    // we have to print the following 
    // values in three part 
    //    1. decimals 
    //    2.hexadecimal
    //    3.octal
    //the size of the values in bytes 
    //maximum values 
    //location for storage 
    //all terminated by the new line char which is called \n 

    printf ("\n at least  8-bit values in decimals:%"PRIdLEAST8 "\n in hexadecimals :%"PRIxLEAST8 "\n in octal :%"PRIoLEAST8 "\n the size :%zu \n the maximum values :%"PRIdLEAST8 "\n location:%p",a,a,a,sizeof(a), INT_LEAST8_MAX,&a);
    printf ("\n at least 16-bit values in decimals:%"PRIdLEAST16"\n in hexadecimals :%"PRIxLEAST16"\n in octal :%"PRIoLEAST16"\n the size :%zu \n the maximum values :%"PRIdLEAST16"\n location:%p",b,b,b,sizeof(b),INT_LEAST16_MAX,&b);
    printf ("\n at least 32-bit values in decimals:%"PRIdLEAST32"\n in hexadecimals :%"PRIxLEAST32"\n in octal :%"PRIoLEAST32"\n the size :%zu \n the maximum values :%"PRIdLEAST32"\n location:%p",c,c,c,sizeof(c),INT_LEAST32_MAX,&c);
    printf ("\n at least 64-bit values in decimals:%"PRIdLEAST64"\n in hexadecimals :%"PRIxLEAST64"\n in octal :%"PRIoLEAST64"\n the size :%zu \n the maximum values :%"PRIdLEAST64"\n location:%p",d,d,d,sizeof(d),INT_LEAST64_MAX,&d);
    




}
