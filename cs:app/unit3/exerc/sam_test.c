#include <stdio.h>


double sam ( int x ,int y ) {

    int m=x;
    if (m==y) {
        printf ("\n m is equal to x :%d", m);



    }
    else {

       printf ("m is not equal to x :%d",x);



   }

return (double ) x;


}

// those are what we wanted just to see on that stages but that shows only the things which are wierd 
int main (){
    int a=79;
    int  b=900;



    double j= sam ( a,b);
    printf (" \n the valueus which is being returned is the this :%lf",j );




} 


