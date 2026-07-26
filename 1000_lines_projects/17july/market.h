 #pragma once
#include <stdio.h>

// this is the market products 

typedef struct {
    unsigned int id;
    unsigned char name[5];
    unsigned char password[10];
    unsigned char email [10];


}users;


typedef struct {
    unsigned long int price;
    unsigned char product_name[10];
    



}products;




// function for dealing with this products 
int create_user (users users) ;
