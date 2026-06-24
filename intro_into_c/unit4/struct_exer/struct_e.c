#include <stdio.h>

typedef int int_def;


int main () {

struct market_info {

char *name;
int_def money ;



};

// then we create the objects 

struct market_info mk1;
mk1.name="sam pray";
mk1.money=1000;


printf ("\nthis is the values of money  i can earn during the day :%s  \n the money i can earn is :%d ", mk1.name,mk1.money);



}
