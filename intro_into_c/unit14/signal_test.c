#include <stdio.h>
#include <signal.h>
#include <unistd.h>



// define my function which will be here for being displayed 
// it will takes the signal and then it will display its number 
void myfunct (int sig) {


    printf ("the macros interapter signal has been clicked :%d",sig);



}


int main (){

    printf (" we are going to print the values which is infinite loop");

    while (1) {

        // we are going to capture the signals which will be generated when 
        // i click maybe ctr+c 
        signal (SIGINT,myfunct);

        printf (" this is infinte loop \n");
       
    // we are going to add the time intervals
    sleep (1);



    }






}
