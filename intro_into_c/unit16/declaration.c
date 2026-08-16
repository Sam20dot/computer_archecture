#include <stdatomic.h>
#include <stdio.h>


// then declarations is defined in three ways 

int main  () {

    _Atomic int var_name;
    atomic_int var_name1;
    _Atomic(int ) var_name2;

    // the size of atomic behavior could be one of the following 
    printf ("\n the size of atomic number is :%zu\n",sizeof (var_name));






}
