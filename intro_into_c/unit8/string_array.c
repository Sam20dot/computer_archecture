// this file contains the files which shows how the arrays can be string
// and how the string is the same as sequencies or array of character 
//this file contains the demostration of the string as the sequencies of the char which can be displayed with the 
//char as like for loop or using the %s format 
#include <stdio.h>


int main () {

char name[11]="sam pray"; // or we can use one char at the time 
char name2[4]={'s','a','m','\0'};

// then we are goig to display this 
for (int i=0; i<11;i++) {
printf ("%c",name[i]);


}

// then we display the last one with the %s 

printf ("the name is :\n%s the name is this one \n",name2);




}
