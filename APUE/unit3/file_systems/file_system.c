#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4000


int main  () {
char buffer [4096];
char message [300]="SAM STORY AND HIS FATHER WHO BOUGHT HIM A GOOD TABLE\0";

  // we first open the file 
  int fd=open ("sam.txt",O_RDWR);
  if (fd==-1) {

      printf  (" faied to open the file \n");
      return -1;
        }

  // then we read the file and its content and so we will need buffer
  ssize_t read_file=read (fd,buffer, BUFFER_SIZE);
  printf  ("\n the amount of the byte we have read are :%ld\n",read_file);

  // then now we are about to add somethings at the beggining of the file 
  // let readfile  we chance the offset 
  off_t change_offset=lseek (fd,0,SEEK_SET);

  // and then write somethings there 
 ssize_t write_message=write (fd,message,300);

 // then we can chose to find where the things are located and then insert there text 
 

 printf  ("\n tell me the amount of file we added here :%ld\n",write_message);






}
