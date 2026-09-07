#include "../harfbuzz/src/hb.h"
#include "../harfbuzz/src/hb-ft.h"


#include<ft2build.h>
#include FT_FREETYPE_H

typedef struct  {

    FT_Library libary;
    FT_Face    face;


} font;

int main () {
// first create the library 
char * filepath="/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf";

    font font;
   int error =FT_Init_FreeType(&font.libary);
   int error1 =FT_New_Face(font.libary, filepath,0,&font.face);

   if (error==FT_Err_Ok) {

       printf (" free type opened very well ");

   }
   if (error1==FT_Err_Ok) {

       printf ("\n the face has been created \n");


   }
   // then we are about to write the harfbuzz font 
   hb_font_t * hb_font=hb_ft_font_create_referenced(font.face);
   // now we create a buffer 
   hb_buffer_t *hb_buffer=hb_buffer_create();


   printf ("\n the library has been initlized \n");


   hb_buffer_destroy (hb_buffer);

   hb_font_destroy (hb_font);



   

}



