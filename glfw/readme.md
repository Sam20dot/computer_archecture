# GLFW :
it mean graphic libray frame works 
## first function 
1. first step is to initilize the communication with the or scanning the 
machine and the required resources provided by the machine it using 
to do that we use the function which is called:

### glfwInit() :
     this function is used for scanning all underying machine properties and 
     design things 

## callbacks :
in programming there is what we call events, those are the actions which happens in given times within machine like connection with game joystics or 
pressing they keys and other things so all are handled with the function which are called the call back functions 
but the main things in programming which can couse us to spend our time chasing error so we have to set the function which help us to track them 
### glfwSetErrorCallback(error_callback);
we pass the error call back to know the error and that call back error has this 
syntax :
     void error_callback (int error const char *discription ) {
        fprintf (stderr,"\n the error happened :Error %s",discription)

     }

## window creation 
to create window we use the function which is called :
 ### glfwCreateWindow (height,width,"title",NULL,NULL);

 this function return the handle or pointer which pointers back to the window created within the memory and also context object on gpu driver as the controller required for designing the things on the screen 
 