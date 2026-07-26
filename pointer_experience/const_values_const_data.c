#include <stdio.h>
// what we say changing over via or over pointer 
// is when we pointer to  a values and try to repoint on it again 
int main () {
    int a;
    int b;

    const int const *p=&a;
    // then let say 
    *p=90;
    // or we will do that 
    *p=&b;

    

}