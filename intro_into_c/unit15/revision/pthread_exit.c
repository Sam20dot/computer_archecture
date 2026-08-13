#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void *myfunct (void *ptr) {

while (1) {


    printf ("\n we are inside my function \n");
    sleep (1);
    pthread_exit (NULL);
    

}

}
void *mmyfunc (void *ptr  ) {
while (1) {

    printf ("we are insed my second function \n");
    sleep (1);
    pthread_exit (NULL);
}

}
int main  () {

    printf ("we are creating threads \n");
    pthread_t thrd1,thrd2;
    int rc=pthread_create (&thrd1,NULL,myfunct,NULL);
    int rc2=pthread_create (&thrd2,NULL,mmyfunc,NULL);


    // then find the values and the ids of the following thread 
    printf  ("\n the ides of the threads are :%lu\n",thrd1);
    printf ("\n the dis of the thread2 are   :%lu\n",thrd2);
while (1) {

printf ("the we are in main functions \n");
sleep (1);

}

}
