#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


// first thread to read file 
void * createFile (void *ptr) {

    int fd=open ("sam1.txt",O_RDWR|O_CREAT|O_TRUNC);
    if (fd==-1) {

        printf ("failed to create the file \n");
         pthread_exit (NULL);
    }
printf ("the same1.txt file has been created and its file discriptor is :%d",fd);
return (void*) (long) fd;

       

}

// then we recieve the file discriptor and then we try to read it 
void *readFile (void *ptr) {

    long *fd;
    fd=(long*)ptr;
    printf ("\n the fd values is :%ld",*fd);




}





int main  () {

    pthread_t thrd,thrd2;
    int rc=pthread_create (&thrd,NULL,createFile,NULL);
    int rc2=pthread_create(&thrd2,NULL,readFile,NULL);
    
    if (rc==-1 && rc2==-1) {

        printf ("\n failed to create thread \n ");
        return -1;
        
    }
    printf  ("\n all thread has been created and the file has been designed in good way\n");


    

    


}
