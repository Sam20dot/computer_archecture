//we are going to write the infinte loop 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



void *myFunct (void *ptr) {

    while (1) {

        printf ("\n inside my function not main ");
        sleep (1);


    }


}


int main () {

    // first we have to create the values which will hold the thread id and when created it will retain or keep its values 
    pthread_t thrd;
    int rc ;
    rc =pthread_create (&thrd,NULL,myFunct,NULL);

    // when it is not created it will return integer values which is not zero so it will be true in false 
    // values 
    if (rc) {
        printf ("\n the thread does did not created \n");
        exit (-1);
        


    }



    while (1) {

        printf ("\n inside main function \n");
        sleep (1);


    }

}
