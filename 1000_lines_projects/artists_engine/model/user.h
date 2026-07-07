#pragma once 

typedef struct {
    char name[1000][10];
    char password[1000][10];





}users;

// then we define the function which will use this one 
int create_user (users *user,int count);

// also to see the users 
int get_users(users user ,int count );

