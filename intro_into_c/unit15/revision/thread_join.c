// we are about to joing two thread 
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>




// aim here is to create a thread which can works together where one read file 
// and other take the ouput of that file and then tell me what is inside 
void * create_file (void *ptr) {

    int fd=open("thread_text.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if (fd==-1) {

        printf (" the thread failed to create a file \n");


    }
    printf ("the file has been created \n");
    printf ("%d\n",fd);


    return (void *) (long )fd;



}
// then we create other function which will take that values and read the file 

void *write_file (void *ptr) {

    int fd= (long)ptr;
    char *message="we are sending this file to you ";
    printf ("%d\n",fd);

    ssize_t write_info=write (fd,message,strlen (message));
    printf ("the file has been writen to the best text \n");


    return (void* )(long) fd;

}

// then we inter within the main function 
int main  ()  {

    // we will return the values likefd
    void *ptr_name;



    pthread_t thrd,thrd1;
    int rc= pthread_create (&thrd,NULL,create_file,NULL);
    pthread_join (thrd,&ptr_name);
    printf ("\n the file has been finished everythings and file has been created\n");

    // then we will call the other file to deal with that to write within that function 
    int rc2=pthread_create (&thrd1,NULL,write_file,ptr_name);
    pthread_join (thrd1,NULL);
    
    printf (" the content has been writen on the file \n");
    return 0;




}
