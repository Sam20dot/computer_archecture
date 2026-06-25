#include <stdio.h>


// first declare the function 
typedef int add_t ;
add_t add (add_t *a, add_t *b) {

	int sum;

	sum =*a+*b;
	return sum;


	


}
int main () {

	int a=90;
	int b=9000;
	int *c=&a;
	int *d=&b;



	// then we add using the actual values 

int sum=	add (c, d);

printf ("\n the sum is the following :%d",sum);





}

	
