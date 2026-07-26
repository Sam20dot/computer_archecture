// we are going to create four thread using the following things 
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // for helping us create the function which will be used for creating those threads 
#include <stdlib.h>



void* funct1() {


    while (1) {


        printf ("\n we are inside function 1 ");
        sleep(1);


    }


}
void *funct2()  {

    while (1) {


        printf (" \n we are here in function2 ");
        sleep (1);

    }

}
void *funct3() {


    while (1) {
        sleep (1);

        printf ("\n print we are inside the function 3");

    }

}
void * funct4 () {


    while (1) {

        printf ("\n we are in function 4  \n");

        sleep(1);



    }

}

// its time to create the threads using ptread 
int main () {

    pthread_t thrd;

    int rc1=pthread_create (&thrd,NULL,funct1,NULL);
    int rc2=pthread_create (&thrd,NULL,funct2,NULL);
    int rc3=pthread_create (&thrd,NULL,funct3,NULL);
    int rc4=pthread_create (&thrd,NULL,funct4,NULL);

    printf ("\n the rc1 is :%d\n",rc1);
    printf ("\n the rc2 is :%d\n",rc2);
    printf ("\n the rc3 is :%d\n",rc3);
    printf ("\n the rc4 is :%d\n",rc4);

    while (1) {


        printf ("\n  we inside main ");
        sleep(1);

    }




}
