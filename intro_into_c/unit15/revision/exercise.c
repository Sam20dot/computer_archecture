// then we are going to write the program 
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

// then create the system which add numbers using thread just doing that in 
// parallel but one every thread do one things and pass results to other 
void * create_number (void *ptr) {

    int a=90;
    printf ("\n the number is :%d\n",a);

    return (void*) (long)a;

}
void *add_number(void *ptr) {
    int a=(long) (ptr);
    int sum=89+a;
    printf ("\n the sum of the two number is :%d\n",sum);

    return (void *) (long)sum;

    
}

// then now we are about to do the square of that numbers 
void *square (void *ptr) {
int sum=(long)ptr;
int square=sum*sum;
printf ("\n the square of two number is :%d",square);

return (void* ) (long)square;
}

int main () {
 
    void *returned_number;
   

    // we first create the thread id for holding those ides 
    pthread_t thrd,thrd1,thrd2;
    int rc= pthread_create (&thrd,NULL,create_number,NULL);
    // when it finish we store its values and within this pointer 
    pthread_join (thrd,&returned_number);

    // then we pass that into the next for doing addition 
    int second_thread=pthread_create (&thrd1,NULL,add_number,returned_number);
    // again about the joing let do that 
    pthread_join (thrd1,&returned_number);
    //and then we create other for doing the solution and do square of the actual number 
    int third_thread=pthread_create (&thrd2,NULL,square,returned_number);

    // then to allow it to finish before main close let first 
    pthread_join (thrd2,NULL);
    printf ("\n we finish with doing all results here for doing more related to the \n the multthread programming \n");





   



}
