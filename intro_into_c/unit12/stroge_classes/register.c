// if we want to access the values at high sped we use the special keyword which is register 
// this key word enable us to write the function which can access those values or 
// to put those valus within the place where to access them is so easier 
//
// but becouse those values in fast register has not expreistry address of the as the stack point do 
// we can not initaiate them as with momery operator & 


#include <stdio.h>

int main () {

    register float a=90;
    printf ("the values is :%f",a);



}
