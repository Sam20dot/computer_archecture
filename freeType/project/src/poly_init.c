
#define SOKOL_IMPL
#include  "../includes/poly_init.h"
#include  "../includes/error_callback.h"




void glfw_Init () {

    /// the comments cames as it was 
    glfwSetErrorCallback (error_callback);

    if (!glfwInit ()) {
        printf ("\n the glfw library failed to load ");
        
    }
    printf (" \n glfw has been initilized !!\n");
    // the initilize for hint and then create the screen and the context 
}




void sokol_init () {
sg_setup (&(sg_desc) {
        .environment= {
           .defaults ={
            .color_format=SG_PIXELFORMAT_RGBA8,
            .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
            .sample_count=1


           }


        }

        });
printf ("\nsokol has been initilized \n");


}

// then now we are about to initlize the freeType to make it works even better 
void freeType_init (fontInit *font,char *pathname ) {

    

    int libray_init= FT_Init_FreeType  (&font->library);

    if (libray_init==FT_Err_Ok) {
    printf ("\nfree type library has been initlized  !!\n");
}

// face 
   int face_init=FT_New_Face (font->library,pathname,0,&font->face);
   if (face_init==FT_Err_Ok) {
       printf ("\nthe face has been created\n ");



   }


}


         

