// function 
#include <stdio.h>

//set balance ;
void set_balance(char name[20],double money);

// this file contains the dispay of pass by refence to the values where the function 
// manipulate of chage the actual values 

#include <stdio.h>


void addBy2 (int* a) ; // this is function prototype 
			       //
int main (){

int a=8;
printf ("\nbefore the adding the number was :%d",a);


addBy2(&a); 
 printf ("\n the values has been changed or added by tw,o :%d ",a);


 

add

}
// function imprementaion 

void addBy2(int *a) {
*a=*a+2;

}
