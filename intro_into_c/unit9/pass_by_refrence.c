// function 
#include <stdio.h>

//set balance ;
void set_balance(char name[20],double money);





	typedef struct  {
		char name[20];
		long int balance;



	}account;

int main (){
	char name[20]="sam pray";
	long int balance =10000000;
// call the function to set the balance ;
printf ("\nthe balance before storing money \n");
printf ("\n balance :%ld\n name :%s\n",balance,name);


set_balance(name,balance);
	printf ("\n after the change :\n balance: %ld \n name :%s");

}


// function definitions 
void set_balance()

