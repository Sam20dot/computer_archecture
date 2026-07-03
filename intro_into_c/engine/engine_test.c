// we first create the fixed amount of the space we want to occupy within the storage to hold our products 
// and becouse we aare createing the data oriented products we will create the structure of arrays 

#include <stdio.h>

#define MAX_PRODUCTS 1000

// then we define the products 

typedef struct {

    unsigned long int stock[MAX_PRODUCTS] ;
    unsigned long int price[MAX_PRODUCTS];
    char name[MAX_PRODUCTS][10];



}products;




// then we create the function which will be used for creating the objects and store those values 
int create_Products (products *product, int count ) {
    for (int i=0; i<count ; i++) {
        printf ("\n ____THE PRODUCT %d ____",i);
        printf ("\n enter your product name :");
        scanf ("%s",product->name[i]);
        printf ("\n enter your price :");
        scanf ("%lu",&product->price[i]);
        printf ("\n enter stock :");
        scanf ("%lu",&product->stock[i]);

        printf (" the product has been created succefully ");
        printf ("\n size of names is :%zu \n address :%p",sizeof (product->name[i]),&product->name[i]);
        printf ("\n the size between the name and products :%ld",(unsigned long int* )(&product->name[i])-(&product->price[i]));
        printf ("\n size of stock is :%zu \n address :%p",sizeof (product->price[i]),&product->price[i]);
        printf ("\n size of stack is :%zu \n address :%p \n ",sizeof (product->stock[i] ),&product->stock[i]);
    
        

    }
    
return 1;


}
//
//calculate the total amount of the products 


unsigned long  int total_amount (products *product,int count ) {

    unsigned long int total=0;

    for (int i=0;i<count; i++) {
        unsigned long int tatal1 =product->stock[i]*product->price [i];
        total+=tatal1;





    } 
    return total;



}

int main () {
// first create the product name and then we enter its names into this part 
products product;

// we are going to create the three products 
create_Products (&product,4);

printf ("\n the total market or the money i have is the following :%lu",total_amount (&product,4));




}
