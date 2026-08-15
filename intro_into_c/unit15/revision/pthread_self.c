// this function help to gets the current id of thread and its prototype 
#include <stdio.h>
#include <pthread.h>


void * myFunct (void *ptr) {
    pthread_t thrdId=pthread_self ();


    printf ("we are inside my function thread \n");
    printf ("\n the id of the current thread is :%lu\n",thrdId);
return (void*)ptr;

}

void *myFunct1 (void *ptr) {

    pthread_t thrdId=pthread_self ();
    printf ("\n the thrread id in second thread is \n");
    printf ("\n thread Id :%lu\n",thrdId);

    return (void *)ptr;
}
int main () {

    // then we are about to create the thread and we send them to works at the sametime 
    pthread_t thrd,thrd2;
    int rc = pthread_create (&thrd,NULL,myFunct,NULL);
    int rc2= pthread_create (&thrd2,NULL,myFunct1,NULL);
    pthread_join (thrd,NULL);
    pthread_join (thrd2,NULL);
    




}
