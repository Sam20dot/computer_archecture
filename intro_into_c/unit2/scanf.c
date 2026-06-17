// this is used for intering the numbers within the machine and read it using keyboard where the numbers inter using 
// the keybard controller and then that data moves ont the conduits and into main ram and then they go back within the memory 
// so let try to use it we will add the numbers and see where they are going to be kept 

#include <stdio.h>


int main () {
	int a;
	while (1) {
// the scanf the valiable it took at the begining of running time it will stay with it for long 


printf (" enter the integer number to see where are going to be stored !");
scanf ("%d",&a);

printf ("\n the number is %d and is located here in memory :%p ",a,&a);

	}}
