#include <pthread.h>
#include <stdio.h>


// we create the function for using different thread for giving us the best 
// for adding two numbers 
void *add_numbers (void *ptr) {
    int a;
    int b;
    int sum;

    pthread_t id= pthread_self ();
    printf ("\n we are at the this id:%ld",id);
    
    printf ("\n number you want to add :\n");
    scanf ("%d",&a);
    printf ("\n enter the second number :\n");
    scanf ("%d",&b);

    // then we do the answer and then return that sum 

    sum=a+b;
    printf ("\n the sum is :%d\n",sum);

    return (void*) (long)sum;



}
// and then we have to do subsstaract from the actual values which has been done
void * sub (void *ptr) {

    printf ("\n the values is :%ld\n",pthread_self ());

    int sum=(long)(void*)ptr;
        printf ("\n the sum here is :%d",sum);

    // and then we will deal
    int sub=sum-100;
    printf ("\n the sub is :%d\n",sub);

    return (void*) (long) sub;



}

// then now we need to know if the thread now has been created and they are going to used 

int main  () {


    void *returned_number;

    pthread_t thrd,thrd1;

    int rc= pthread_create (&thrd,NULL,add_numbers,NULL);

    // THEN USE WHAT WE CALL pthread_join (thread_id,and returned values );
    pthread_join (thrd,&returned_number);
    printf ("\n the returned value is :%ld",(long)returned_number);

    int sub_num=pthread_create (&thrd1,NULL,sub,returned_number);

    // to prevent main to not quit we have to make the pthread_join but with 
    // a condition 
    pthread_join (thrd1,NULL);
    printf ("\n we have finished to write the numbers \n");


    




}
