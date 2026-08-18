#include <stdio.h>


int main () {

    // first open file using file pointer 
    FILE* fp=fopen ("fputs.txt","w");

    if (fp==NULL) {

        printf (" failed to open or create a file ");
        return -1;



    }
    fputs ("why people does not like to deal with text as i do ",fp);
    fclose (fp);
return 0;


}
