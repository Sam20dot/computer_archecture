// we are going to create the event loop  which is infinit 
#include <signal.h>
#include <unistd.h>
#include <stdio.h>


// the function 
int main () {
    signal (SIGINT,SIG_IGN);


    while (1) {


        printf ("\n the infinit loop has been started !!");
        sleep(4);


    }

}

