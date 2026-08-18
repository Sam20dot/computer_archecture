//from the book which is called advanced programming in unix enviroment 
//we have read that we can use the low level programming but there are frame works 
//or standard library which has been designed to abstract and improve perfomance 

#include <stdio.h>


int main  () {

 FILE *fp=fopen ("sam.txt","w+");
 fprintf (fp,"we are here to do the best what other things for now ");
 fclose (fp);


}
