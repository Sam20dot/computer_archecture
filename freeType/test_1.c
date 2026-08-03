#include <stdio.h>

typedef struct {

    char name[10][15];




}names;

int main () {
    

    names name;
   for (int i=0; i<10; i++) {

       printf ("\n enter your name :\n");
       scanf ("%s",name.name[i]);

   }

   printf("\n all names are this one ");
   for (int i=0; i<10; i++) {

       printf ("%s\n",name.name[i]);

   }
   printf ("\n");


}
