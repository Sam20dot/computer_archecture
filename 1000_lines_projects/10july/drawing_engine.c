// we are going to write the game engine which will draw the things on the screen 
// here we will first drwa the line which will be printed on the screen to show the size of the screen as the screen as it 
#include <stdio.h>

#define MAX 133
#define HEIGHT 40




int main () {
    char name[10] ;
    printf ("enter your name :");
    scanf ("%s",name);

    int maximum= MAX-10;
    





    for (int i=0; i<maximum; i++) {
        // to draw the holizantal line 
        printf ("_");                                                                                                          



    }
    printf ("\n");
    // then the other line which will be vertical to be drwan 
    for (int i=0; i<MAX ; i++) {
        printf ("|");
        printf ("name is :%s",name);
               for (int i=0;i<maximum;i++){



        printf (" ");


    }
    printf ("|");
    

    printf ("\n");
    


}
// the line for closing the line at the buttons 
for (int i=0; i<MAX; i++) {
printf ("_");

}
printf ("\n");
}








