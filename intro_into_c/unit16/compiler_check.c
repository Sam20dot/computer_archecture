#include <stdio.h>
#include <stdatomic.h>



int main () {

#ifdef __STD_NO_ATOMICS__
    printf ("no atomic behavoir for this compiler");


#else 
    printf ("atomic are supported \n");
#endif 


}

