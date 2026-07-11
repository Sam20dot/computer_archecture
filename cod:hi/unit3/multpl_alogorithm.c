// this file contains the multplications alorgorithm which  can be used to do
#include <stdio.h>


#define MAX_STEPS 32

int main () {
int multplier=0b0011;
int tester=0b0011;                            //this is here to help us to test if the last number is zero 
int multplicand=0b11000;
int product=0b0000000000000;

printf ("\nthe product is :%#b",product);
printf ("\nthe multplicand is :%#b",multplicand);
printf ("\nthe multplier is :%#b\n",multplier);

for (int i=0; i<MAX_STEPS;i++) {

// it says that if multplicant0 =1 we do the following 
// add multplicand to a product and place it in the product registers 

    if ((multplier && tester)==1 ) {


        // we take the multplicand and then we add that to the products 
        product +=multplicand;

        printf ("\n the product values on step %d is the following :%#b \n",i,product);


        // then shift left multplicand 
        multplicand <<=1;
        printf ("\n the multplicand is :%#b\n",multplicand);

        // then we shift right the mulplier right 
        multplier >>=1;
        printf ("\n the multplier is :%#b\n",multplier);
        
    }
    else {
        // if the least bit is equal to zero we do nothings like we dont add that into the product registers 
        // and even we just shift that only 
        printf ("\n the product values on step %d the following :%#b \n",i,product);

        multplicand <<=1;
        printf ("\n the multplicand is :%#b\n",multplicand);

        // then we shift right the mulplier right 
        multplier >>=1;
        printf ("\n the multplier is :%#b\n",multplier);
        



    } 
   

}
// the answers of the product is the following 

printf ("\n the final product is the following :%#b\n",product);



}
