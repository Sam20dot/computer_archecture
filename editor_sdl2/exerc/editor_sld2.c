#include <SDL2/SDL.h>
#include <stdio.h>
#include <signal.h>


void* terminate_window (SDL_Window *window) {

    SDL_DestroyWindow (window);
    SDL_Quit();
    printf ("my function called ");




}



int main () {


    printf ("\nwe are here to find what is best \n");
    // then we are going to first start the video engine or part 
    if (SDL_Init (SDL_INIT_VIDEO)<0) {
        printf ("failed to initate");

        return -1;


    }

    // then we create the window 
    SDL_Window *Window = SDL_CreateWindow ("sam editors",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,900,0);

// then we create the window surface 
    SDL_Surface *surface_window = SDL_GetWindowSurface (Window);

    // test if window has been created 
    if (!surface_window) {

        printf ("window does not created ");
        return -1;

    }

    // box 
    SDL_Rect box;
    box.w=400;
    box.y=0;
    box.h=178;
    box.x=10;



    // then we will refile the surface 
    SDL_FillRect (surface_window,NULL,0x0F647A);
    SDL_FillRect (surface_window,&box,SDL_MapRGB(surface_window->format,225,225,200));
    // then update the screen 
    SDL_UpdateWindowSurface(Window);
    SDL_Delay (1000000);
    // then manage it to tell the os that we are still alive 
    SDL_PumpEvents();
    signal (SIGINT,terminate_window (Window));








}
