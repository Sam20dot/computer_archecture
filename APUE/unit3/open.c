// this is the file for opening the file 
#include <fcntl.h>
#include <unistd.h>


// we start with the opening the file which is on this part 

int main () {


    int fd=open ("sam.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
    dup2(fd,STDOUT_FILENO);
    close (fd);

}
