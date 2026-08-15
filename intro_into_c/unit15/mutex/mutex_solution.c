#include <pthread.h>
#include <stdio.h>



// my first function will take a frobal valiabel and incrment it 
// and other will take it and declement it 
int global_v;
pthread_mutex_t mtx;



void * increment (void *ptr) {

    // then we lock within the function inside 
    pthread_mutex_lock (&mtx);

    printf ("we are inside this file :%ld",pthread_self ());

for (int i=0; i<1000000000;i++) {

  global_v ++;


}
printf ("\n the global value is :%d\n",global_v);

pthread_mutex_unlock(&mtx);


}

void *declement (void *ptr) {

    pthread_mutex_lock(&mtx);
    printf ("we are inside this file :%ld",pthread_self ());


    for (int i=0;i<1000000000; i++) {

        global_v--;


    }

    printf ("\n the global value is :%d\n",global_v);


    pthread_mutex_unlock (&mtx);

}
// and then in main we will create the values and thread to deal with that 

int main  () {
    printf ("main start \n");


  


    pthread_t thrd1,thrd2;
    
    if (pthread_mutex_init (&mtx,NULL)!= 0) {

        printf ("\n the mutex initlization has been failed \n");
        return -1;



    }

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

    // and now we introduce the lock 


    // AND THEN WE PRINT THat values which has been initilized 
    printf ("\n the global valiable is :%d\n",global_v);

    // then we destory the mutex values
    pthread_mutex_destroy (&mtx);

    return 0;



}

