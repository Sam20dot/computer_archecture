// thi is what we are dealing with 
#include <stdio.h>
int main (){
// then we are going to write the things for constant pointer which pointes to the 
// const values 
int a=32;
const int *p=&a;

// then we can not change the values 
*p=90;
// we get the error 
printf ("\n you can not update this number :%d",*p);

/*
 *
 *p_const_v.c: In function ‘main’:
p_const_v.c:10:3: error: assignment of read-only location ‘*p’
   10 | *p=90;
      |   ^  which shows that we can accessing thsi values 
 *
 * */
}

