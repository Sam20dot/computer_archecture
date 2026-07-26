// first let create the structure 
#include <stdio.h>


typedef struct {
  unsigned char name[10];
  unsigned char pass[10];


}users;

// then we will use the array of the user 


int main () {


    users user[3];
   static int  count =0;

    while (count<3) {

        printf ("\n enter your name :");
        scanf ("%s",user[count].name);
        printf ("\n enter your password:");
        scanf ("%s",user[count].pass);
        count+=1;


    



    }
    for (int i=0; i<count; i++) {
    printf ("the user name and password is :\n %s \n password :%s",user[i].name,user[i].pass);

    }

    


}
