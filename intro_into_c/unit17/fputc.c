#include <stdio.h>


int main  () {

    FILE* fp;
    fp=fopen ("fputc.txt","w");

    if (fp==NULL) {

        printf ("\n the file has been failed to be opened\n ");
        return -1;


    }
    // and then use the fputc to write a single character on the screen 
    fputc ('H',fp);
    fputc ('e',fp);
    fputc ('l',fp);
    fputc ('l',fp);
    fputc ('o',fp);
    fclose (fp);




}
