// we are going to write the codes which can be used to demostrate the exact length of the integer and 
// dipslay how they are being used for uinsigned this values also show the size the maximum and minimum of that 
// files and codes that why sam like to write the codes maybe ai will read becouse people tihs days they dont like 
// to write them selves codes 
// i want to have the obsession like Ken in 1969 when he wrote the unix version  i can call it 1 in three weeks 
// let that mind set and inspirations cames upon me and allow me to write the codes everyone can enjoy 
// i am the man who will inspire the last generation to be crougius 
//
// this example is going to be written in 15 min max and then we are on 7/15/2026 1:17 after noon
// i finish this at 7/15/2206                                                     1:34 


#include <stdio.h>
#include <inttypes.h> // we add this becouse those fixed N-bit integers are defined within that header 



int main () {


    // the first task is to write declare the values using uintN_t 

    uint8_t        a;
    uint16_t       b;
    uint32_t       c;
    uint64_t       d;


    // the second task is to write the prompt for user to int those values 
    printf ("\nenter the first values of uint8_t :");

    scanf ("%"SCNu8"",&a);

    printf ("\nenter the second value of uint16_t:");

    scanf ("%"SCNu16"",&b);

    printf ("\n enter the third value of uint32_t:");

    scanf ("%"SCNu32"",&c);

    printf ("enter the fourth values of unit64_t :");
    
    scanf ("%"SCNu64"",&d);

    // task 3 to display those values with the following display :
    // 1. values in 
    //        decimals 
    //        hexadecimal
    //        octal 
    //        binary ?? but this one there is not mcros which has been specifed for it 
    // 2. size of the values 
    // 3. location where they are supposed to be stored 
    // 4.maximum values 
    printf ("\n the value of a in decimal is:%"PRIu8 "\n in hexadecimal :%#"PRIx8 "\n in octal :%#"PRIo8 ":\n the size :%zu \n location :%p \n maximum values :%"PRIu8 "",a,a,a,sizeof(a),&a,UINT8_MAX);
    printf ("\n the value of a in decimal is:%"PRIu16"\n in hexadecimal :%#"PRIx16"\n in octal :%#"PRIo16":\n the size :%zu \n location :%p \n maximum values :%"PRIu16"",b,b,b,sizeof(b),&b,UINT16_MAX);
    printf ("\n the value of a in decimal is:%"PRIu32"\n in hexadecimal :%#"PRIx32"\n in octal :%#"PRIo32":\n the size :%zu \n location :%p \n maximum values :%"PRIu32"",c,c,c,sizeof(c),&c,UINT32_MAX);
    printf ("\n the value of a in decimal is:%"PRIu64"\n in hexadecimal :%#"PRIx64"\n in octal :%#"PRIo64":\n the size :%zu \n location :%p \n maximum values :%"PRIu64"\n",d,d,d,sizeof(d),&d,UINT64_MAX);




}

