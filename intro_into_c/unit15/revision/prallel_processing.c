#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * myFunct (void *ptr);
void * myFunct1 (void *ptr);



int main () {

  

    // then we intilize the one which will hold the thread id 
    pthread_t thrd;
    pthread_t thrd1;
    int rc2=pthread_create (&thrd1,NULL,myFunct1,NULL);
    
    int rc=pthread_create (&thrd,NULL,myFunct,NULL);
    if (rc==-1) {

        printf ("failed to create the thread");
        return -1;


    }
    
    while (1) {
      



        printf ("we are inside loopa\n ");
        sleep (1);

    }
   

}

 void *myFunct(void *ptr) {


    while (1) {

        printf ("inside my function\n");
        sleep(1);



    }

}

void *myFunct1 (void *ptr) {
while (1) {

    printf (" the third thread in the process \n");
    sleep(1);



}

}


