// this file shows the limits of file which can be created or one process can open 
#include<unistd.h>
#include <stdio.h>
#include <limits.h> 
#include <fcntl.h>

// for getting the open max file 
                    //


int main () {
int file=creat("sam5.txt",O_RDONLY);
int file1= open("pray.txt",O_WRONLY|O_CREAT| O_TRUNC);



    printf ("the maximum the file or process can create is :%d",FOPEN_MAX-1);
    printf ("the file discriptor is :%d\n",file);
    printf ("\n the file open why is not working %d\n",file1);

    


}
