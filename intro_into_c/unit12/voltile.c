// in voltile what happen is that we prevent the compiler to apply the optimization methods so that the 
// values can be changed imediatly like the interaputers or other things which are most needed to change every time 
#include <stdio.h>


int main () {



    volatile int a=90;

    printf (" \n the values as voltile must be insured as \nthe value which will be changed  :%d" ,a);

    


}
