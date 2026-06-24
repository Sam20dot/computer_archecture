// this file will contains the structure as pointers
#include <stdio.h>

int main () {

// first structure 
typedef struct {

char *name;
char *ouner;



} food;
food f1;

// then we assaing the values 
f1.name="avocado";
f1.ouner="sam";


// then we create the pointer 
food *fp=&f1

// then here we wil use allow access to access them 

printf ("\n the name of the products is :%s \n the ouner is :%s \n",fp->name,fp->ouner);



}
