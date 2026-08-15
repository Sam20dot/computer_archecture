// when we use pthread_detach all its values and memory are freed so taht 
// we can prevent the memory leak 
// let try it now 
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *hello_remove(void *message) {
 
    char* msg=(char*) (void*)message;

    printf ("the message is :%s\n",msg);
    int a=90;
    printf ("\n the value is ");

    return (void*) (long)a;
    
}

// i want to see if i can use its values after using pthread_detach
int main ()  {

    char *message="we are here to make someone happy";

    void *returned_v;

    pthread_t thrd1;
    int rc=pthread_create (&thrd1,NULL,hello_remove,message);
    pthread_detach (thrd1);

while (1) {

printf ("we are here to be happy\n");

sleep (2);


}
    //pthread_join (thrd1,&returned_v);
    printf ("\n we finish");







}

