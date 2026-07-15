// then here we are going to use those values 
//  the reason why we use those marcos is to prevent those values to give us hard time for printing like 
//  in printf we can use %d but maybe on that values 32 bit represent the long word so to prevent we se those macros 


#include <inttypes.h>
#include <stdio.h>


// then we are going to print or to show this 
int main (){
int8_t a=122;


printf ("the values is %"PRId8" \n",a);
printf ("the value also is :%"PRIi8" \n",a);
printf ("size of the val of int8_t:%#"PRIx8" size :%zu",a,sizeof (a));




}
