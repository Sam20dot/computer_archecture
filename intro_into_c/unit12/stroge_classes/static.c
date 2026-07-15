// this is not common but static values : they retains they values until the programm terminates 
// to mean that i can create a function which will first declare the valuesa nd then keep imprementing it 
// to mean that this values will act as it declared in the grobal and those function are just changing it 
// and i think this is usefull for holding like creadentials for a systems in running and keep storing the states 
// the syntax is : static data_type valiable_name =values ;


#include <stdio.h>

void  myFunct () {


    static int a=290;
    a++;

    printf ("\n the values inside the functions is :%d \n",a);






}

int main () {

    myFunct();
    myFunct();
    myFunct ();







}
