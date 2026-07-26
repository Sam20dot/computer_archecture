// this file shows how the signal can be igonored so when we are dealing with this interactive 
// signals which are being nerated by software 
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// we will se micros which is signal igonare 
// SIG_IGN

int main () {




    printf ("\n we are showing what :");

    while (1){


        signal (SIGINT, SIG_IGN);
        printf ("\n we are igonaring signals ");


    } 


}



