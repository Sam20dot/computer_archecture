#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


// the buffer size 





int main () {
    int buffer[300];


    // first we create the file 
    int fd= open("Created_f11.txt",O_RDWR|O_CREAT|O_TRUNC);
    // then we read write somethings in that file 
    char name[200];
    printf ("enter the text to write \n");

    scanf ("%s",name);
    ssize_t fd_write=write (fd,&buffer,200);
    if (fd_write==-1) {
        return -1;


      }
      printf ("the values size of the things writtien is :%lu \n",fd_write);

    

}
