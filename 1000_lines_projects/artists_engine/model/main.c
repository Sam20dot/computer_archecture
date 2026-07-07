#include <stdio.h> 
#include "user.h"
#include "string.h"

int main () {

    int count=3;

    users user;




    printf ("welcome_sam_command_line : ");
    while (1) {
        char cmd[10];
        
        printf ("\n enter :cr_u to create user ");
        printf ("\n enter :get_u to get users\n");
        printf ("\n command_sam $:");
        scanf ("%s",cmd);

        if(strcmp(cmd,"cr_u")==0) {
            // we create the user
            int count1= create_user ( &user,count );
            count1=count;
            printf ("\n the values of count is :%d",count);

             



        }

        else if (strcmp (cmd,"get")==0) {
            printf ("we are counting ");
            get_users (user,count);
            


        


         }
            
            




        
        else {

            printf ("\n you have entered wrong values ");




        }
        
    }


    }







