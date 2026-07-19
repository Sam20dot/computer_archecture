#include <stdio.h>
#include <SDL2/SDL.h>
#include <signal.h>
#include <unistd.h>

int main ()  {

   if ((SDL_Init(SDL_INIT_VIDEO))<0) {
    printf ("the object has not been created ");
    return -1;

   }

   // then we create the object 
   printf ("\nwe are going to create the widow \n");
   SDL_Window *pwindow= SDL_CreateWindow("sam_editor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,899,766,0);
   SDL_Surface *window_surface=SDL_GetWindowSurface(pwindow);

   if (!window_surface) {
    printf ("the window surface has not seen here ");
    return -1;

   }
   
   // allow user to change the colour
   int color_times;
   printf ("enter the number of window you want to create :");
   scanf ("%d",&color_times);

   for (int i=0; i<color_times; i++) {
    signal (SIGINT,SIG_DFL);

    // ask user to put the widow color to change it 
    int color;
    printf ("\nenter the color of the editor:");
    scanf ("%x",&color);



   SDL_FillRect (window_surface,NULL,color);
   // then we update the screen 
   SDL_UpdateWindowSurface(pwindow);
   SDL_PumpEvents();


   // then we delay for a given time 
   SDL_Delay (3000);


   }
   // then we close the window 
   SDL_DestroyWindow (pwindow);
   SDL_Quit ();
   printf ("finaly the screen has been created using my energy about 1hour of debugging \n");
   

   
  







}