#include <stdio.h>


int main () {


    FILE* fp=fopen ("readText.txt","r");
    char str[900];

    fscanf (fp,"%s",str);
    printf ("\n the string is :%s\n",str);


    fclose (fp);
    return 0;

    


}
