#include <stdio.h>


// this is the exercise which are going to take almost 10 min about the struct 


int main () {
// first structure :
struct motor {

char l1;
char l2;
char l3;

char v_type;

short int mNumber;


};

// the next structure is the car structure 
struct car {

char l1;
char l2;
char l3;
char l4;
char v_type;
short int mNumber;



};


// then here we are going to create the object for each in altenating i want to see if they will still grouped to gether 

struct motor m1= {.l1='R',.l2='F',.l3='A',.v_type='M',.mNumber=120};
struct car c1= {'R','A','A','C','D',299};
struct motor m2;
m2.l1='R';
m2.l2='A';
m2.v_type='M';
m2.mNumber=222;
m2.l3='X';

// then we will create the other things for the cars
struct car c2;
c2.l1='R';
c2.l2='B';
c2.l3='F';
c2.l4='E';
c2.v_type='C';
c2.mNumber=124;

// then now i want to see where thoes values if are all in the same places or if they are bein altenated for now 
printf ("\n THE EXERCISES FOR SHOWING THE ACTUALLY IF \n STRUCTURE STAY IN THE SAME CONTINGUES MEMORY PART AS ONE \nAS ONE VALIABLE ");

// we are going to print the address of each object file as they are 
printf ("\n the address of the motors are in the following location :\n");
printf ("\n m1 :%p\n",&m1);
printf ("\n m2 :%p\n",&m2);

// so then we will go and see the objects of the car where are being deployed 

printf ("\n THE CAR OBJECT LOCATIONS IN MEMORY");
printf ("\n car1 :%p \n",&c1);
printf ("\n car2 :%p \n",&c2);

// the size of intire objects 
printf ("\n \n the size of objects \n");
printf ("\n the size of motor object :%zu \n the size of the objects of cars :%zu\n",sizeof(struct motor),sizeof(struct car));
// and then let display those things on the screen thier plate numbers 

printf ("plate_number of motor 1 is :\n%c%c\n%hi%c \n motor2 :\n%c%c\n%hi%c \n categories: %c\n",m1.l1,m1.l2,m1.mNumber,m1.l3,m2.l1,m2.l2,m2.mNumber,m2.l3,m1.v_type);


printf ("\n plate_number of car1 is :\n%c%c%c\n%hi%c  car2 :\n%c%c%c\n%hi%c categories: %c\n",c1.l1,c1.l2,c1.l3,c1.mNumber,c1.l4,   c2.l1,c2.l2,c2.l3,c2.mNumber,c2.l4,c2.v_type);



}
