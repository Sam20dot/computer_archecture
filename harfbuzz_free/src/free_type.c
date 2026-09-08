#include "../include/free_type.h"

 int free_type_init (Font *font, char * pathname,unsigned int pixel_size) {

     int lib_init=FT_Init_FreeType (&font->library);
     if (lib_init==FT_Err_Ok) {

         printf ("\n freetype library has been created !\n");


     }

     int new_face=FT_New_Face (font->library,pathname,0,&font->face);
     if (new_face==FT_Err_Ok) {

         printf ("\n the new face has been initlized correctly \n");


     }
     // 
     int pixel_sizes=FT_Set_Pixel_Sizes (font->face,0,pixel_size);
     if (pixel_sizes==FT_Err_Ok) {

         printf ("\n the pixel size is :%d\n",pixel_size);

     }

     return 1;



 }



