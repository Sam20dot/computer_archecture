#include <stdio.h>


// then we are going to write the function syntax
/* syntax :
 * returned_data_type function_name (data_type var1,data_type v2,.....) {
 * // here we put the statemens 
 *
 * retured values ;
 * and they must be declared out of main or we can use other methods for using the function 
 * prototype and then use function call and function prototype 
 *
 *
 * }
 *
 *
 *
 * */


float add (float a,float b);

int main (){

float a;
float b;
printf ("enter the values :\n");
scanf ("%f %f",&a,&b);

float sum =add (a,b);

printf ("\n the sum is :%f",sum);


}

// then here we are going to declare the funcitons 
float add (float a,float b) {

	return a*b;
	
}
