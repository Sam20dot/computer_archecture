#include <stdio.h>


// then we first write the int main as the main function 
int main () {


// then we will first declare the arrays 
int memory_int[10];

for (int i=0; i<10;i++) {

memory_int[i]=i*4; // we use the int so that they can imitate the how the int values are stored within the memory of machine 


}
printf ("\n the mimic of the memory address of the integer within the memory ");

// then we are going to display those whole numbers 
for (int i=0; i<10;i++) {
printf ("\naddress :%#x \n the actual address is :%p\n",memory_int[i],&memory_int[i]);

}


}
