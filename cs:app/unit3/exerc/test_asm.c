// then here we are going to write the structure and the function like is function which takes the structure 

#include <stdio.h>

struct mystruct {

int a;
int b;
int c;


};

// function which pass by pointing to the pointer 

int max_numb(struct mystruct *ssa) {
    
  
if (ssa->a > ssa->b && ssa->a >ssa->c ) {
printf ("\n a is maximum ");

}
else if (ssa->b >ssa->a && ssa->b>ssa->c) {
printf ("\n  b is maximum ");


}
else {
    printf ( "\n the value of c is maximumc \n ");


}
return ssa->a;



}


// then we  compile them to see what will happen 
