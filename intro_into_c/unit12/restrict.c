// restric is used to tell the cpu or other compiler that this value must be accessed with only one pointer 
// to mean that we can not point two or three values to access those values in the memory which are restricted used 
// in embeeded systemss 
#include <stdio.h>


// we define the function which uses the pointers and other which does not and one hwich uses the restrict 

int myFunction (int *ptra, int *ptrb,int *ptrc) {

    // the pointer a  can access the values within ptrc and then do some pofromance or do somethings 


    *ptra+=*ptrc;

    printf ("\n the values has been perfomed :%d",*ptra);


    // the part of the program is used for display the following 
    *ptrb += *ptrc;
     printf ("\n the values has been perfomed :%d",*ptrb);

     return *ptrc;







}


// if we use restricts we can do assaign to pointer to acces the same values in the memory that can not be able to be done 
// 

// let test this 
int main () {
    int a=90;
    int b=908;
    int c=88848;


    myFunction(&a,&b,&c);




}
