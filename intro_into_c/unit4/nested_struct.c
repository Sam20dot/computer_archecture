#include <stdio.h>
#define PI 3.14


// then here we are going to create the nested structures 

typedef struct {

int x;
int y;
int area;


struct cylender {
int radius ;

}s2;


}diagram;

// then we are going to do the codes which find the area of the sylender 
int main (){

diagram d1;
d1.x=324;
d1.y=323;
d1.s2.radius=32;


// the area of the cylender is equal 
 d1.area=PI*d1.x*d1.y*d1.s2.radius*d1.s2.radius;

 printf ("\n the area is :%d",d1.area);

}




