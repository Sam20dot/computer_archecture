#include <pthread.h>
#include <stdio.h>



// my first function will take a frobal valiabel and incrment it 
// and other will take it and declement it 
int global_v;


void * increment (void *ptr) {
for (int i; i<1000000000;i++) {

  global_v ++;


}

}

void *declement (void *ptr) {

    for (int i;i<1000000000; i++) {

        global_v--;


    }

}
// and then in main we will create the values and thread to deal with that 
int main  () {

    pthread_t thrd1,thrd2;

    // and then we create rece condition 
    int rc1=pthread_create (&thrd1,NULL,increment,NULL) ;
    int rc2=pthread_create (&thrd2,NULL,declement,NULL) ;

    if (rc1==-1 && rc2==-1) {

        printf ("failed to initilize the resources \n");
        return -1; 


    }
    // and then we join for main to wait for them to terminate and give us the 
    // results 
    pthread_join (thrd1,NULL);
    pthread_join (thrd2,NULL);

    // AND THEN WE PRINT THat values which has been initilized 
    printf ("\n the global valiable is :%d\n",global_v);
    return 0;



}

