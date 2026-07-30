// this file is for creating files using only create function within this places 
#include <unistd.h> // for unix finding 
#include <fcntl.h> 
// for using other part
#include<stdio.h>



int main () {



    // create file 
    int fd=creat("samFile.txt",O_RDONLY);
    printf ("the open file is one :%d\n",fd);

    // then we can close the file 
    close(fd);
    printf ("file discriporn2 closed\n");

    





}
