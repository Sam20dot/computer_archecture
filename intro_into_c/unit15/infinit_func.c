#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>




void *myFunct (void *ptr ) {


    while (1) {


        sleep(1);
        printf ("\n inside my funct");

}

}
int main () {


    pthread_t thrd;

    // then create the thread 
    int rc= pthread_create (&thrd,NULL,myFunct,NULL);


    if (rc) {
        printf ("the thread has been failed to create ");
        exit (-1);



    }

    while (1) {


        sleep (1);
        printf ("\nwe are inside main \n");



    }


}
