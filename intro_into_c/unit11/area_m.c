#include <stdio.h>




// then we define the pi to use it when we are calcucating the value of area 
#define PI 3.14

int main () {


 int r;
 printf ("\n enter the area_radius value here : \n");
 scanf ("%d",&r);
 if (r==0) {
printf ("\n the radius is equal to zero try again  ");


 }
 else {


     // we calculate the area
     int area =PI *r*r;
     printf ("\nthe area of cycle is the following :%d \n",area);
     

 }



}
