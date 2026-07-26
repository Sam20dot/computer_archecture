
#include <stdio.h>
#include <string.h>



typedef unsigned char *byte_pointer;

void show_bytes (byte_pointer start ,size_t len) {


    int i;
    for (i=0; i<len ; i++ ) {


        printf ("%.2x",start[i]);
        printf ("\n");

    }

    
    }


// the function to show int 
void show_int (int x) {


    show_bytes ((byte_pointer) &x, sizeof (int ));


}

// show the int in order like little indian stored within the memory 


void show_float (float y) {

    show_bytes ((byte_pointer) &y,sizeof (float ));



}

void show_pointer (void *x) {

    show_bytes  ((byte_pointer) &x ,sizeof (void *));


}


int main () {
    int a=9000;
    const char *m ="sam pray";




    show_int (43);
    show_float (333);
    show_pointer (&a);
    show_bytes ((byte_pointer) m, strlen (m));




}
