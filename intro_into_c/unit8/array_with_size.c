#include <stdio.h>


int main (){

// then we are going to declare the values which is no values in memory and we are going to show that how we compiler can do that for us 
int array[]={3,4,5,6,4,3,4,5,7,6,7};

// first over all we have to know the size of arrays 
printf ("\n the size of array is :%zu",sizeof (array));



// then we check the values of the array one by one 
printf ("\n the first number is :%d\n the second number is :%d \n the third number is :%d\n the third number is :%d\n",array[0],array[1],array[2],array[3]);
// we the size of the arrays is 44 becouse we have the 11 values where every valiable has only 4 bytes of memory that why they are equal like that

/*we must pay attention becouse when we try to access the index which is greater that the one which has been declarad albiraty values are shown
 * as the following example has shown for that 
 *
 * */
printf ("\n show the values which are beyond the array size :%d\n",array[100]);

// to prevent the above problem for reading the data outside the data we can use the besic mathematics 
// as follow we can first calculate the size of an array and then with whole size array over the single size of array and we use that as leng and use for loop to loop through all values 
//
printf ("\n THE VALUES WHICH HAS BEEN CALCULATED BEFORE THE ARRAY EVEN LOOP START TO AVOID GOING BEYOND \n");
int length=sizeof (array)/sizeof (array[0]);

for (int i=0;i<length;i++) {

// then here we print all values 
printf ("\n the number is :%d \n",array[i]);




}


}
