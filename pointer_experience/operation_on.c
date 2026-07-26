// the values for operating on the pointers 
#include <stdio.h>


int main () {
    int a=90;
    int *p=&a;
    int count=0;
    



    // increment the values of the 
    while (count<2) {
        (*p)++;
        // *p++; // here we get the segmentation foult becouse it affect the access of this avlues 
        // and it  access out of the memory or ouput 



    }
    

 
    


    printf ("the increment of pointer values %d \n  ",a);
}