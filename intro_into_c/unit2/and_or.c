// for or,and we will use two header one is for standard input and ouput and other is for boolean 
#include <stdio.h>
#include <stdbool.h>



// then the main function 
int main () {

	bool a=true;
	bool b=false;

	// first we compare them as with and operator 
	bool c =a && b;
	bool d =a||b;

	printf ("\n THE LOGIC OPERATOR WITH OR AND AND ___\n ");
	// show the numbers 
	printf ("\n the bool of a and b are the following :%d, :%d respectively",a,b);

	// and gate and nor gate 
	printf ("\n the and gate is of a and b is :%d",c);
	printf ("\n the or gate of a and b is     :%d\n",d);





}
