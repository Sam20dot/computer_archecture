// here we are going to see the integer size using the sizeof function 
// and this operator its return type is long unsigned values and then we are going to check 
// on my machine how long int is taking within my memory now 
#include <stdio.h>

int main (){

	printf ("\nthe size of int is %lu",sizeof (int));

// we can also do the declarations to see how that could be 
int sam_ages=21;
printf ("\nsam's agaes which are %i are holding about %lu bytes of memory \n",sam_ages,sizeof (sam_ages));





}
