#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myFunct (int sig) {


    printf ("\n sam is doing what is hard to be the best programmer in the whole world :\n MARCO:%d \n",sig);


}



int main () {

    while (1) {


        signal (SIGINT,myFunct);
        



    }
}
