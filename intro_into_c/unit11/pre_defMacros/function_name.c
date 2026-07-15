// this predefined macros can be used for just the function name 
#include <stdio.h>


void wowo_name () {


    printf ("\n the function name is :%s \n ",__func__);

}

int main () {

// here we are going to print the function name here is main 
    printf ("\n the function name is :%s \n",__func__);

    // and then we are going to wrrite the function name which is wowo_name 
    wowo_name ();



}
