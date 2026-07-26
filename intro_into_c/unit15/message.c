// how we pass the values and see the values like that of the message 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *messageShow (void * arg) ;


int main () {


    pthread_t thrd;
    int rc;
    char *msg="what made up someone who dont know what it means ";

    rc= pthread_create (&thrd,NULL, messageShow,(void*)msg);
    if (rc) {

        printf ("\n the student are good at finsinding the best tools ");


    }
while (1) {
    sleep (1);
  printf ("\n the other things which can be possible");








}


}
// function definitions 
void *messageShow (void *arg) {
char *msg=(char *) arg;

while (1) {
    sleep (1);

printf ("%s",msg);
printf ("\nwe are in my function ");

}



}



