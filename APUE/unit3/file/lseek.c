// seek in programming mean to move the head of the physical head of the disk pointer to read or repositioning the file a
//and read the file unsequency
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


// then we are going to show that 
int main () {


    // we first create the file 
    int fd=open("sam.txt",O_RDONLY| O_CREAT |O_TRUNC);
    // then we will seek or jump within this file 
    off_t curposs=lseek (fd,0,SEEK_SET);
    printf ("the current possition is :%ld",curposs);


}
