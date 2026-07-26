#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>



// structure for computation
typedef struct {
    int a;
    int b;
    int sum;

}Data;


// create a function to keep add those numbers 
void * addNumber (void *arg) {

Data *data= arg;

while (1) {

data->sum =data->a+data->b;
printf ("we are in addNumber funct ");

data->sum +=data->sum;



sleep (1);
}
return NULL;





}

// then we will create the thread to add that in parallel 
int main () {


    // we create the thread value which will hold the id of the thread vales 
    pthread_t thrd;
    pthread_t thrd1;

    // and then we create the values 
    int sum=0;
    int a=90;
    int b=48;

    Data data={a,b,sum};

    int rc;
    int rc2;
    rc2=pthread_create (&thrd1,NULL,addNumber,&data);

    rc= pthread_create (&thrd,NULL, addNumber,&data);
    if (rc) {
        printf ("\n the error has been happened for creating this thread \n ");
        exit (-1);

        


    }

    while (1) {
    printf ("\n the sum is :%d \n",data.sum);
    sleep (1);
    }






}
