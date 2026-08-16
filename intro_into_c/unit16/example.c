// this example demostrate how we prevent the race condition to happen 
// using atomic data and conditions 
#include <stdatomic.h>
#include <stdio.h>
#include <pthread.h>


atomic_int global;

int variable;
void * myfunct (void * ptr);
void *myfunct2 (void *ptr1);

// then we came in main function 
int main  () {

    pthread_t thrd1,thrd2;
    int rc1=pthread_create (&thrd1,NULL,myfunct,NULL);
    int rc2=pthread_create (&thrd2,NULL,myfunct2,NULL);

    // then we join them to let the main wait for them 
    //until they finish what whey will be doing 
    pthread_join (thrd1,NULL);
    pthread_join (thrd2,NULL);
    printf ("\n the value of the global is :%d\n and valiable is :%d\n",global,variable);
    // THEN PRINT 
    printf ("\n the now we finished to use atomic functions \n");



}

// now we define the functions 
void * myfunct (void *ptr) {

    for (int i=0; i<10000; i++) {

        global++;
        variable++;
  }


}


void *myfunct2 (void *ptr1) {

    for (unsigned int i=0; i<10000;i++) {

        global --;
        variable --;



    }


}
