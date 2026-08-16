// we are about to deal with the lock free and unlock free  functions 
// the first function is 
// atomic_is_lock_free(const volotile A *obj);
#include <stdio.h>
#include <stdatomic.h>


int main () {

    _Atomic int a;
    //_Atomic int b[1000];

    printf ("\n enter the atomic is :%s \n",\
            atomic_is_lock_free(&a) ?"look-free\n":"is not loock free\n");
   // printf ("\n the atomic values is :%s\n", atomic_is_lock_free(&b) ?"look-free":"is not lock free");
   
    a=89;

    int ret;
    ret=atomic_fetch_add (&a,43);

    printf ("\n the changed values is :%d\n",a);
    printf ("\n the original values is:%d\n",ret);






}
