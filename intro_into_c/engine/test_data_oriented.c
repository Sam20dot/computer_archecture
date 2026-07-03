// this file is intended to check the array to works with 
// the goal for now is to write the array which will do the store as many things as possible and 
// then we will make the choosing from the all \\
// so we will start with the things which are hard like creating the array of products, arrays of prices, and arrays of things which 
// works well 
// we will add the function which will be used to add the values in that arrays on the same index 

// we start with function which declare the function and insert the values on the same index to be mapped together
// it will takes the arrays and then add the values in 


// check the array other 
/*#include <stdio.h>

int main  () {

    int a[3][4] = {{2,3,4,5},{5,4,3,2},{4,4,5,4}};
        for (int i=0; i <3; i++) {
            for (int j=0; j<4; j++) {
                printf ("%d ",a[i][j]);

            }
            printf ("\n");

        }


    }
*/


// then now we are going to do array of names  
/*#include <stdio.h>

int main () {

char name[3][10] = {"sam pray","keve","big man "} ;

for (int i = 0; i<3;i++) {
    printf ("\nthe name is :%s ",name[i]);


}



}
*/

// then other things are the following is to write the function which will add the values iwthin the arrays now we create for the
// for the states 
#include <stdio.h>


int create_account (char *name, int price[], int stock[],int data_a,int index) {


    for ( index=0; index<data_a; index++) { 


    printf ("\n enter your name :");
    scanf ("%s",name);
    printf ("\n enter your price inventory :");
    scanf ("%d",&price[index]);
    printf ("\n enter your stock :");
    scanf ("%d",&stock[index]);
    
    printf ("the product was created successfully");
    }
    return 1;





}
int main () {
    char *name;
    int price[1000];
    int stock[1000];


while (1) {

create_account (name,price,stock,1000,0);


}

}





