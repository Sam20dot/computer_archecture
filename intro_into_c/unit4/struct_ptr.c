// this is structure pointer which used to point back on that value which has been declared within the part 

#include <stdio.h>
typedef struct valiables var;

struct valiables {
int x;
int y;
int z;
int m;



};



// then we create first object 
//then now we are going  to go in the main function 
int main () {

var v1={3,4,2,5};

// then we declare the pointer which point on the actual part of the variables 
var* sptr=&v1;

// then we access this infromations using -> for showing or pointing where those data are in the memory 
printf ("\nthe data are pointed within the data  memory here like this \n");
printf ("\n the value x is located :%d location :%p ",sptr->x,&v1.x);
printf ("\n the value y is located :%d location :%p ",sptr->y,&v1.y);
printf ("\n the value z is located :%d location :%p ",sptr->z,&v1.z);
printf ("\n the value m is located :%d location :%p \n",sptr->m,&v1.m);


}
