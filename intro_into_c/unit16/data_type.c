#include <stdio.h>
#include <stdatomic.h>
#include <stdbool.h>




int main () {

    atomic_bool           a=true;
    atomic_char           message='v';
    atomic_schar          m=225;
    atomic_short          s=90;
    atomic_ushort         b=89;
    atomic_int            c=23000;
    atomic_uint           d=90000;
    atomic_uint           e=99999990;
    atomic_long           f=399999999990000;
    atomic_ulong          g=23889899999999999;
    atomic_llong          h=38838838293838;

    // then print those all values 
    printf ("\n ATOMIC BEHAVIOR ");
    printf ("the size of bool  is :%zu\n",sizeof        (a));
    printf ("the size of short is :%zu\n",sizeof        (b));
    printf ("the size of char  is :%zu\n",sizeof (message) );


    

   


}
