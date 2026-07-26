
#include <stdio.h>


typedef struct {
    unsigned int id;
    unsigned char name[5];
    unsigned char password[10];
    unsigned char email [10];


}users;

typedef struct {

    unsigned long int product;
    unsigned long product_name[10];



}products;




users user;
int create_user (users *user){



    printf ("enter the your name :");
    scanf ("%s",user->name);
    printf ("enter your password ");
    scanf ("%s",user->password);
    printf ("enter your email;");
    scanf ("%s",user->email);

    return 1;
}




int main () {


    users *user;
    int user1=create_user(user);
    if (user1==1) {
        printf ("\nthe user has been created ");
        printf ("\nthe user name is :%s",user->name);
        printf ("\nthe user name is :%s \n",user->email);





    }




}
