// we are about to use the function which is called memo copy 
#include <stdio.h>
#include <string.h>



#define MAX_LENGTH 80

int main () {

    char source[MAX_LENGTH]="we are writing the code every one can use !!";
    char target[MAX_LENGTH]="this is the target source string";
    // before copy we have the following 
    printf ("the target is :%s \n",target);
    memcpy (target,source,sizeof (source));
    printf ("\n after the copy we have this :%s \n",target);
return 0;




}
