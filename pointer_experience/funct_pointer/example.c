// this is the example which shows the function pointer in this file 
#include <stdio.h>

int  add_numbers(int a,int b) {
    return a+b;

}

int main () {
    // we design the pointer which point to that function 
    int (*fn) (int ,int);


    // and then we assaing it to avaliable 
    fn=add_numbers;
    int  sum =(*fn)(43,45);


    printf ("the added number is :%d\n",sum);


}