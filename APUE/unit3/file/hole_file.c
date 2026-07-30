// creating the file which has the hole inside it 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// then we declare the buffer to write on the file 
char buf1[]="abcdefjhi";

char buf2[]="ABCDEFGJHI";


int main () {
int fd;
if ((fd=creat("file.hole",O_RDONLY))<0) {


    printf ("file created ");


} 

// then we write into that file 

if (write(fd,buf1,10)!=10) {
printf ("failed to write and buffer size is long \n");


}
// now offset if equal to ten then let increase it to create holes within the file 

if (lseek(fd,16384,SEEK_SET)==-1) {


    printf ("they failed to initilize that file with that size !!! \n");


}

// then we write again 
if (write(fd,buf2,10)!=10){


printf ("\n the file is not created !! \n");
}

}
