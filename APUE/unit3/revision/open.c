#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>





int main  () {

int fd=creat("sam.txt",O_RDONLY); 
printf ("\n the file has been created and its values is :fd :%d",fd);
printf  ("\n the limits of file name is :%d",NAME_MAX);


}
