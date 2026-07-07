// then we are going to define the files here to see what they are how they are working
#include "stdio.h"

#include "user.h"


int create_user (users *user,int counter ) {

    for (int i=0; i<counter; i++) {

    printf ("\n enter the user name :");
    scanf ("%s",user->name[i]);

    // ask user to inter his password 
    printf ("\n enter the password :");
    scanf ("%s",user->password[ i ]);
 
 printf ("\n the user created successfully");
 
    }
    return 1;





}


// then to get all users 
int get_users(users user ,int count) {
    for (int i=0;i<count; i++) {

    
        printf ("\n the user name is :%s", user.name[i]);
        printf ("\n the user password is :%s ",user.password[i]);
        printf ("i values :%d",i);
        
    }



    
return 1;


}
