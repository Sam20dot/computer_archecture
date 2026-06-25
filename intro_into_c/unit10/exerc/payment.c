// thi file contains the structure for paying the money and also and the two function to allow the client to 
// pay using those values like but we have to create the object which pointer exactly to the location of the starting 
// of that structure and then we will use those values intothose function 
// 1. we start with creating the structure, then function for seting names , and for setting balance 


#include <stdio.h>

// structure 

typedef struct {

char *name;
long long int balance;


}

payments;


// then we create the pointer to that to that object 
void  addName(char *name,payments *p) {
	// and then we will set the name to the following
	p->name=name;
	




}

// then add balance 

void setBalance (long long int *balance,payments *p) {

p->balance=*balance;

}

// then the main part 

int main () {
// object 

payments p;
payments *p1=&p;

long long int  amount=1000;
char *name="sam pray";


addName(name,p1 ) ;
setBalance (&amount,p1);
// then printf the values 

printf ("\n the name of the owner is :%s \n the amount he deposite :%lld \n",p1->name,p1->balance );




}
