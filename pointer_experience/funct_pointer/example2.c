#include <stdio.h>


char* print_name(char *name) {
    
    return name;

}


int main () {

    // then we create the pointer which points back on the same function 
    char* (*name)(char *) ;

    name=print_name;

   
    printf ("\n the values are :%s \n",(*name)("hello sam"));

}