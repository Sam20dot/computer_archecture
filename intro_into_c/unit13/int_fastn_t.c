// we are going to write the codes which will help us to explore the  at least vales of bits but also what will be fast on the machine usages 


#include <stdio.h>
#include <inttypes.h>




int main () {
// declarations 
 
    int_fast8_t           a;
    int_fast16_t          b;
    int_fast32_t          c;
    int_fast64_t          d;

// ask user for input the codes 

    printf ("\nenter at fast  8-bit number :");
    scanf ("%"SCNdFAST8"",&a);
    printf ("\nenter at fast 16-bit number :");
    scanf ("%"SCNdFAST16"",&b);
    printf ("\nenter at fast 32-bit number :");
    scanf ("%"SCNdFAST32"",&c);
    printf ("\nenter at fast 64-bit number :");
    scanf ("%"SCNdFAST64"",&d);


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

    printf ("\n at fast  8-bit values in decimals:%"PRIdFAST8 "\n in hexadecimals :%"PRIxFAST8 "\n in octal :%"PRIoFAST8 "\n the size :%zu \n the maximum values :%"PRIdFAST8 "\n location:%p",a,a,a,sizeof(a), INT_FAST8_MAX,&a);
    printf ("\n at fast 16-bit values in decimals:%"PRIdFAST16"\n in hexadecimals :%"PRIxFAST16"\n in octal :%"PRIoFAST16"\n the size :%zu \n the maximum values :%"PRIdFAST16"\n location:%p",b,b,b,sizeof(b),INT_FAST16_MAX,&b);
    printf ("\n at fast 32-bit values in decimals:%"PRIdFAST32"\n in hexadecimals :%"PRIxFAST32"\n in octal :%"PRIoFAST32"\n the size :%zu \n the maximum values :%"PRIdFAST32"\n location:%p",c,c,c,sizeof(c),INT_FAST32_MAX,&c);
    printf ("\n at fast 64-bit values in decimals:%"PRIdFAST64"\n in hexadecimals :%"PRIxFAST64"\n in octal :%"PRIoFAST64"\n the size :%zu \n the maximum values :%"PRIdFAST64"\n location:%p",d,d,d,sizeof(d),INT_FAST64_MAX,&d);
    




}
