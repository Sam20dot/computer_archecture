// in the extern the valiable or the function is declared as the extern it's memory is allocated imediatry as they are declared 
// that why we use it as in the following exmple 
#include <stdio.h>


extern float myFunct (float a,float b) {


    return a*b;




}


// then we show other which is not extern 
float myFunct1 (float a ,float b ) {
    return a*b;

}

// then compile but with using the assembly to check thier ouput 

