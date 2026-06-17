/*


// here we are going to use the atenative of structure for much cleaner and faster ways to do that 
#include <stdio.h>

int main () {

typedef struct motors cars ;

struct motors {

short int number;

};
 motors m1;
m1.number=1;

printf ("\n the motora is the first one really :%hi\n",m1.weight);


// the second one is
struct cars {

double weight;



};
 cars c1;
c1.weight=89458.9999;
printf ("\n the cars weight are :%lf \n",c1.weight);

// and then we will add also he part of the buses 


}
*/


/*
 * the above codes there was misunderstood of how the typedef works to mean it define the type definition 
 * example : if i write the following 
 * typedef struct  myStructure mystr;
 *
 *this mean that all of those are structure but at differnet levels
 // it mean that : STRUCT MY STRUCTURE is equal to MYSTR so where i supposed to use it i will replace it there 
 // in bellow example 
 *
 * */

#include <stdio.h>


int main (){



typedef int  b;
typedef long int li;
li number=90000;

b c=9;
printf("the number of c is :%d\n",c);
printf("\nthe long number with using type def is :%li\n ",number);

// then we are going to bring that within the structure as follow 

typedef struct student std ;
typedef char ch;
typedef int i;

struct student {
	ch student_g;
	i marks;



};
//then we use the part of the student to show how that actual works 
std s1;
s1.student_g='A';
s1.marks=90;

printf ("\nthe infromations of the student are the following \n");
printf ("the grades :%c \n the student marks :%d\n",s1.student_g,s1.marks );


}
