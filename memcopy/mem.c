#include <string.h>
#include <stdio.h>


int main  () {

    char buffer [1024]="        ";
    char new_buffer[1024]="when Sam Pray want to do this exercise he will do the following";

    // then we copy that space i have there and copy within this file 
    printf ("\n the buffer new_buffer before was ;%s\n",new_buffer);

    memcpy (new_buffer,buffer,sizeof (buffer));
printf ("\n the buffer will change to empty space :%s,",new_buffer);
return 0;

}
