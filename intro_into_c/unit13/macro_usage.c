// BUILD YOUR SELF WE HAVE TO FINISH THIS UNIT TODAY NOT TOMORROW AND REMEMEBER YOU HAVE DISTROYED YOUR DAY 
// BY WAKING UP AT 10:42 SO WE HAVE TO RETURN THAT ALL TIME YOU HAVE WASTED 


//we are going to use those macros for sized widith integer values to test how big they are and how they are used 
//for printing them and also to use scan to scan them and also to show the size they have and also the space they occupy in memory 
//this project is going to takes only 10 min 
//


#include <stdio.h>
#include <inttypes.h>

int main ()  {


    int8_t    a;
    int16_t   b;
    int32_t   c;
    int64_t   d;

    // then we are going to use the marcos for scanning those values
    printf ("enter the first number :");

    scanf ("%"SCNi8" ", &a);

    printf ("enter the second number :");

    scanf ("%"SCNd16"", &b);

    printf ("enter the third number :");

    scanf ("%"SCNd32"", &c);
    
    printf ("enter the fourth number:");

    scanf ("%"SCNd64"", &d);


    // then in the following print we have the following display 
    // the values in decimal ,hexadecimal, octal binary  , size and locations in the memory 
    printf ("\n the value of a in decimal is :%"PRId8 "\n in hexadecimal :%#"PRIx8"  \n in octal :%#"PRIo8"  \n binary:%#"PRIX8 "\n size :%zu\n address :%p\n",a,a,a,a,sizeof(a),&a);
    printf ("\n the value of a in decimal is :%"PRId16"\n in hexadecimal :%#"PRIx16" \n in octal :%#"PRIo16" \n binary:%#"PRIX16"\n size :%zu\n address :%p\n",b,b,b,b,sizeof(b),&b);
    printf ("\n the value of a in decimal is :%"PRId32"\n in hexadecimal :%#"PRIx32" \n in octal :%#"PRIo32" \n binary:%#"PRIX32"\n size :%zu\n address :%p\n",c,c,c,c,sizeof(c),&c);
    printf ("\n the value of a in decimal is :%"PRId64"\n in hexadecimal :%#"PRIx64" \n in octal :%#"PRIo64" \n binary:%#"PRIX64"\n size :%zu\n address :%p\n",d,d,d,d,sizeof(d),&d);








}
