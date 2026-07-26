// signal can be handled by defoult function which has been registered 
// for that function let try to the one which will handle the ctrl+c
#include <stdio.h>
#include <unistd.h>   // for getting sleep function 
#include <signal.h>



int main() {



    printf (" we are showing the infinite loop :\n");

    while (1){


        signal(SIGINT, SIG_DFL);
        printf ("\n we are showing what loop look like ");


    }
        


}
