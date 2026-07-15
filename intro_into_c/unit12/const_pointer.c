// this file contains the pointer things which can be shown here as the best way to do the thing
#include <stdio.h>


int main () {


    int a=90;
    const int *ptr=&a;
    int c;

    // this mean that the value we are pointing to can be changed or you can not assaign the new values there
  // this gives error becouse the values we are pointing to is read only values   *ptr=43;
  
    // the other cas is that when a pointer can not point to other values 
    int b=90;
    int const *ptr1 =&a;
   // this also shows error becouse is read only valibalbe s not assainable  *ptr1=&c;

}
