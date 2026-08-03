#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>



int main () {

    printf ("the limits of byte i can read  are :%lu",SSIZE_MAX);
    int buffer[3000];
    // first we have to open the file and then get the file discriptor 
    int fd= open ("sam_text.md",O_RDONLY);
    if (fd==-1) {
        printf ("there are error in opening file ");

    }

    ssize_t fileSize=read(fd,buffer,2000);
if (fileSize!=-1) {

    printf ("\n the file is well read the values is :%lu",fileSize);


}
printf ("the file size is :%lu\n",fileSize);
int i=0;

while (i<3000) {

printf ("%c",(char)buffer[i]);
i++;



}
printf ("\n");



}
