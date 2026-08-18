#include <stdio.h>

int main  () {

    FILE* fp=fopen ("myFile.txt","w");

    // and then we add data inside it 
    if (fp==0) {

        printf ("\n failed to be opened \n");
        return -1;
        


    }

    fprintf (fp,"we are writing within this file ");
    fprintf (fp,"we are adding the marks of the student %d",89);




}
