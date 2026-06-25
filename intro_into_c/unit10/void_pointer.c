// this is the null pointer before we have the pointer like the pne which is int* or char * and others 
// for now we are going to deal with those which can be where we have to deal with that 
#include <stdio.h>


int  square  (void *p)
{
	int multp= *(int*)p* *(int *)p;
	return multp;

}

//then we came in main to deal with
double square_double (void *p ) {

	double multp= *(double*)p* *(double *)p;
	return multp;

}

int main () {

int a=200;
double b=2000;
int values1=square (&a);
double values2=square_double (&b);
printf ("\n the values of the values1 :%d \n  the values2 :%lf",values1,values2);



}
