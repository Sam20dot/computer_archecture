#include <stdio.h>


int main () {
FILE* fp=fopen ("readText.txt","r");
int ret;

char str[900];


if (fp==NULL) {

    printf ("\n we failed to open the file \n");
    return -1;


}
// and then for now i want to read by using the loop inside the file 
while (1) {

    ret=fscanf (fp,"%s",str);

    
    if (ret==EOF)        break;
        
        printf ("%s \n",str);
    




}


return 0;


    


}
