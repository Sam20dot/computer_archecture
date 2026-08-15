#include <pthread.h>
#include <stdio.h>


// function one for adding numbers 
// and passing the message from one to onather 
void *add_number (void *number) {

    int a,b;
    printf ("\n enter n1:\n");
    scanf ("%d",&a);
    printf ("enter n2:\n");
    scanf ("%d",&b);

    // and then do the answers 
    int sum=a+b;
    printf ("\n the sum is :%d",sum);


    return (void *) (long)sum;


}
// and do the adding those number to see the output and outcome 

void *sub_num (void *sum) {

    int asum =(long) (void *)sum;
    // and then we do substraction
    int sub=asum-1000;
    printf ("\n the sub is :%d\n",sub);

    return (void *)(long)sub;




}


// and then we are about to find th ebest way to find the best way 
// of cordinating this thread to works together 
int main () {
pthread_t thrd1,thrd2;
void *returned_number;

// then we are about to go down let see what will happen
// thread one cameon
int add_thrd=pthread_create (&thrd1,NULL,add_number,NULL);

// and then we join them to mean that after it finish we will take the 
// data it will return and then we use them 
pthread_join (thrd1,&returned_number);

// and then we pass this values within the next part 
int sub=pthread_create (&thrd2,NULL,sub_num,returned_number);
pthread_join (thrd2,NULL);

printf ("thread finish thier works so now we are about to finish :jjjjjjj\n");






}

