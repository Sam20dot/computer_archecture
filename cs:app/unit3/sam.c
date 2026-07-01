#include <stdio.h>

#define sam_o  435;

// then we define the function 

int add (int a,int b) {
int sum =a+b;
return sum;

}
int main (){

int a=43;
int b=32;
int sum;
sum =a+b;
printf ("\n the sum is :%d",sum);

printf ("\n the next is the things which will showing the function excution \n");


int samm=add (a,b);

int sam_1=samm+sam_o;

printf ("\n the values of the samm is :%d",sam_1);

return 0;

}
