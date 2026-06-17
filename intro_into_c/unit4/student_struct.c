// this is the structure which has been designed for the student to show thier ages, marks, and grades 
// second to show how does data will be shown in the memory and also showing the space between them 
#include<stdio.h>


int main () {
// we start with initializing or declaring the structure called student 
struct student 
{
	short int ages;
	int marks;
	char grades;

};

// then we create the object from there as the following 
struct student s1; // to mean that this is the first student to use that structure of the infrmations 

s1.ages=12;
s1.marks=32;
s1.grades='A';

// the second structure 
struct student s2;


//then we first by knowing how much space that structure occupy 
printf ("\n THE STRUCTURE INFO SHOWN ON THE SCREEN RIGHT NOW\n \n  ");
//
//printing the size 
printf ("the size of the structure is :%zu \n",sizeof ( struct student ) );
//
//then we are going to dispay all infrmations of the student and occupation of that values using address 


printf ("\n the student ages is :%hi\n the student marks are:%d \n the student grades are :%c",s1.ages,s1.marks,s1.grades);
printf ("\n the storage of those data \n ages:%p\n marks:%p \n and grades :%p ",&s1.ages,&s1.marks,&s1.grades);
printf ("\n the structure of from address :%p\n and %p\n",&s1,&s2);

// the first one has occupied rage space so let try to reduce them 
struct std_space_rd {
// here we are going to arrange the data so that the first one is char and second is short int and the last is int as follow 
char grades;
short int ages;
int marks ;


};

// then we assaing or intialize the data the first way i beig familier is this one 
struct std_space_rd s3;


// then we add the values 
s3.grades='A';
s3.ages  =22;
s3.marks =98;


// then first we check the size of the structure ;
printf ("\n__REDUCED SPACE STRUCTURE BY ORDERING FROM THE SMALLSET TO THE HIGHEST ___\n");
printf ("\n the size of structure is :%zu", sizeof (struct std_space_rd));

printf ("\n the student has grades :%c \n has ages :%hi years old \n and marks of :%d",s3.grades,s3.ages,s3.marks);
printf ("\n the address of each are grades :%p\n the address of ages is :%p\n the address of marks is :%p \n",&s3.grades,&s3.ages,&s3.marks);

// then we define the other part which is next structure 
printf ("\nlocation of s3 is :%p\n",&s3);
struct std_space_rd s4;
printf ("\nthe location of s4 is :%p \n ",&s4);

// to finish the initilization we are going to practice by creating almost 2 student and then use the disgnated intializer

struct std_space_rd s5 ={'A',22,89};

// the above is short and smart but look like pro but is not amazing like using str.valirable names and then valiable 

printf ("\n the student 5 has the following \n grades:%c\n ages: %hi \n marks :%d\n ",s5.grades,s5.ages,s5.marks);


// then the way to use the disgnated initializer list 

struct std_space_rd s6 ={.grades='C',.ages=32,.marks=50};

printf ("\n the marks of student 6 are the grades:%c\n ages :%hi \n marks :%d \n",s6.grades,s6.ages,s6.marks);
// so let see now the space we have occupied for each struct 
printf ("\naddress of s1 :%p\n",&s1);
printf ("\naddress of s2 :%p\n",&s2);
printf ("\naddress of s3 :%p\n",&s3);
printf ("\naddress of s4 :%p\n",&s4);
printf ("\naddress of s5 :%p\n",&s5);
printf ("\naddress of s6 :%p\n",&s6);







}
