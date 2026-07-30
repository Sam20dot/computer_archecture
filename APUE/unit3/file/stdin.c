// we are going to see the position of the offset within this file 
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>



int main () {

    // for current offset

    // BASED ON THE HEAD OR START 
    // on the final of the file or rlated to the ends of the file 
    // to mean that it will read all files to the ends of the files 
    // the current offset is :502
    off_t std=lseek (STDIN_FILENO,0,SEEK_END);
    if (std==-1) {

        printf(" we faied to load the values \n");

    }
    else {
        printf ("the current offset is :%ld \n", std);
        

    }


//lseek it help us to travel through the file without just scanning it all 
//and if we make the file intractive we can read the file from the current position 
// 
  //  sam@LAPTOP-L8C5S9KQ:~/holday_learning/APUE/unit3/file$ ./sam <lseek.c
//    the current offset is :0sam@LAPTOP-L8C5S9KQ:~/holday_learning/APUE/unit3/file$


}
