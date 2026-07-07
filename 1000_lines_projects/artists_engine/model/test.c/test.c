// then we are going to test this files 
#include <stdio.h>


typedef struct {

    char name[1000][10];
    char password [1000][10];



}users;

// then we write the function which can set the values in the structure and then the one which can show 
// use the valeus from that structure 
int create_user (users *user,int count ) {
// what we will do we will create every user part 

    for (int i=0; i<count ; i++) {

        printf ("\n enter the user name :\n");
        scanf ("%s",user->name[i]);

        printf ("\n enter the password : \n ");
        scanf ("%s",user->password[i]);

    




    }
    return 1;



}

int main () {

// let see if we can get the user which has been set by the users 
users user;

// then first create those users in the memory
printf ("create user ");
create_user (&user,2);

// then we show those wto people 
for(int i=0 ; i<2; i++) {



    printf ("\n the user set by the functions are :\n");
    printf ("\n the user name is :%s",user.name[i]);
    printf ("\n the user password is :%s \n",user.password[i]);


}
printf (" we have done the best job ");

}
