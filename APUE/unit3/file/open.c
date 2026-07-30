// this is other ways of creating file but not using the creat function but using the open function with other flags 
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>



int main () {


    int fd=open ("file.txt",O_RDONLY|O_CREAT| O_TRUNC);
    printf ("the file created and opened by operating systems\n and its file discriptor is :%d\n",fd);



}
