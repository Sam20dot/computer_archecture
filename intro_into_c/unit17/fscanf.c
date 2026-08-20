#include <stdio.h>
#include <time.h>


// and now we are about to read that file 
int main  () {
    struct timespec start,end;


     char message[6777];
     int count;



    FILE * fp=fopen("benchmark.txt","r+");
    FILE *fp1=fopen ("readed.txt","w+");

    // THEN READ IT 
// then we define measurement 

    if (clock_gettime (CLOCK_MONOTONIC,&start)!=0) {

        perror ("failed to start the file long changing \n");


    }
while(fscanf (fp,"%s",message)!= EOF) {
        printf ("we count:%d\n",count);
            fprintf (fp1,"%s",message);

         count++;

   }
// we end the session 
if (clock_gettime (CLOCK_MONOTONIC,&end)!=0) {

    perror ("\n we have failed to close the timing \n");

}

// then we calculate the actual time 
double elaspse= (end.tv_sec-start.tv_sec)+(end.tv_nsec-start.tv_nsec)/10e9;
printf ("\n it took this time to open read a file :%0.6lf\n",elaspse);

    // and then we write this message back in other file called read message space by space 

printf ("\n the message has been written here \n");
// then we close the file 
fclose (fp);
fclose (fp1);

return 0;





}
