

#include <stdio.h>

#define MAX_STEPS 32


int multp_algorithm (int multplier,int multplicand,int steps) {
    int multplier_reg   =       multplier;
    int multplicand_reg =       multplicand;
    int tester          =       0b0001;
    int product         =       0b000000000;

    // first we print what we started with so that they can be visible even the change which are being done 

    printf ("\n multplier is  :%#b",multplier);
    printf ("\n multpicand is :%#b",multplicand);
    printf ("\n the product is:%#b",product);

    // then now we are going to start to multpliy using the methods we used for testing and shifting 32 times 

    for (int i=0; i<steps;i++) {
        printf ("\ntester is :%#b\n",tester&& multplier_reg);



        //step one : we check if the least significand bit of multplier is equal to 1 
        //* if is equal to one we take the multplicand values and we add that to the product 
        //** we shift the multplicand to the left by one 
        //*** we shift the multplier to the right by one also 
        if ((tester && multplier_reg)==1) {
            product +=multplicand_reg;
            printf ("\n the product at step :%d is %#b ",i,product);
            multplicand_reg<<=1;
            printf ("\n the shifted left of multplicand is :%#b",multplicand_reg);
            multplier_reg>>=1;
            printf ("\n the shifted right of multplier  is :%#b",multplier_reg);
        }

        /*
         * when the least values of the multplier is equal to zero we will do 
         * we doesnt change the product values but we keep shifting those values 
         * until we finish 32 steps 
         *
         * */

        else {
             printf ("\n the product at step :%d is %#b ",i,product);
            multplicand_reg<<=1;
            printf ("\n the shifted left of multplicand is :%#b",multplicand_reg);
            multplier_reg>>=1;
            printf ("\n the shifted right of multplier  is :%#b",multplier_reg);




        }


    }
    printf ("\n the overall product is :%#b \n",product);

    return product ;




}

int main () {

int multplier;
int multplicand;

printf ("\nenter the multpler :");
scanf ("%b",&multplier);
printf ("\n enter multplicand :");
scanf ("%b",&multplicand);


multp_algorithm(multplier,multplicand,MAX_STEPS);



}
