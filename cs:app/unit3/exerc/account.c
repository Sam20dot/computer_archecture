// this is the project of people who is new and he want to create account within the within my app 
#include <stdio.h>
#include <string.h>
typedef struct{

    // for better data arignement we have to roder them from small to the big one ;
    unsigned long int balance ;
    char name[8] ;
    char password[10];



} account ;

// then we create the function which will get the following things 
// 1. to create account 
int create_account (account  *account) {
    


    printf ("\n enter your name :");
    scanf ("%s",account->name);
    printf ("\n enter your password : ");
    scanf ("%s",account->password);
    printf ("\n enter the amount you want to deposit :");
    scanf ("%ld",&account->balance);
    return 1;



}

// then we create other function for get the account 
int get_account( account *account ) {
    // first tell the user to put his or he password
    // first we do the swap 

    
    char pass[10];
    printf ("\n enter your password :");
    scanf ("%s", pass);

    // then loop through all the object to see if there is anymatch found in the questions 
    
        if (strcmp(pass,account->password)==0) {
            printf ("\n the user name is    :%s  \n",account->name);
            printf ("\n the user balance is :%ld \n",account->balance );




        }
        else {
            printf ("you have entered wrong password ");


        }


    

return 1;

}

// then now we are going first to test this one ;
int main () {
/// first we create the object 
account acc;

// then we create account 
int status=create_account (&acc);

if (status==1) {

    printf ("\naccount created successfully\n");


}
else {
    printf ("\n ! creating account failed \n");


}
// then we are going to get the account 
get_account (&acc) ;






}

