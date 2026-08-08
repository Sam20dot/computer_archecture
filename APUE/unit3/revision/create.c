#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main() {


    int fd= open("sam.c",O_WRONLY|O_CREAT|O_TRUNC); // mode is optional
    printf  ("\n the file has been created withe following fd :%d\n",fd);



}
