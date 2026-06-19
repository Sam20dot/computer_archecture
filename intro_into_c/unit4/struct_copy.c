#include <stdio.h>


struct student_info {
char name[20];
char password[20];



};
int main () {
struct student_info std1 ={.name="sam",.password="1234"};
struct student_info std2;
std2=std1;


// then we copy the student info into student two
// forgetting main 






printf ("\n this is copy of struct from the following \n student name :%s \n student password is :%s\n",std1.name,std1.password);
printf ("\n the copy of student one is here in this file \n student name:%s \n student password is :%s \n ",std2.name, std2.password);

}

