// this is the first sam project done before 12:00 am during in july 
// i have to love machine as computer to make it more doing what i want and make good tools to do many things as 
// someone loves piano or his or her pet 

#include <stdio.h>
#include <string.h>



// then we are going to tell the user to write the word and then we first have to draw the frame around it 
int main () {

   
    

    while (1) {

          char name[10];
    printf ("character1 :");
    scanf ("%s",name);

    char your_name[10];
    printf("\t\t\t\t\t\t\t\t character2 : ");
    scanf("%s",your_name);


   
    unsigned long length= strlen(name);


    for (int i=0; i<length+2;i++) {

        printf ("_");




    }
    printf ("\n|");
    printf (": %s",name);
    printf ("|\n");
    // then we put the other on the bellow of the whole words 

    for (int i=0; i<length+2;i++) {

        printf ("_");


    }
    printf ("\n");

    // ask the name to be printed on the other side of the terminals
    


  

    printf ("\t\t\t\t\t\t\t\t :%s\n",your_name);

    }




    // we are going first to test if we can display the things on the other side of terminals
    


   




}
