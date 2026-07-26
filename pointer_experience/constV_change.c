// we can change the value of the constant valiable using the 
// pointer 
#include <stdio.h>

int main () {
    const int a=90;
    printf ("\n the values before change is :%d",a);

    int *p=&a;
    *p=89;
    printf ("the pointer betrayed me :%d",a);
    


}