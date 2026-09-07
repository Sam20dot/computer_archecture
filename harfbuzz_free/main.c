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
char * filepath="/usr/share/fonts/truetype/ubuntu/Ubuntu-C.ttf";

    font font;
   int error =FT_Init_FreeType(&font.libary);
   int error1 =FT_New_Face(font.libary, filepath,0,&font.face);

   if (error==FT_Err_Ok) {

       printf (" free type opened very well ");

   }
   if (error1==FT_Err_Ok) {

       printf ("\n the face has been created \n");


   }

   // first we set the pixel size 
   int pixel_size= FT_Set_Pixel_Sizes (font.face,0,48);
   
   if (pixel_size==FT_Err_Ok) {

       printf ("\n the pixel size has been set to 48  \n");


   }
   // then we are about to write the harfbuzz font 
   hb_font_t * hb_font=hb_ft_font_create_referenced(font.face);
   // now we create a buffer 
   hb_buffer_t *hb_buffer=hb_buffer_create();

   // then we add the utf 
   hb_buffer_add_utf8 (hb_buffer,"hello world we want someone",-1,0,-1);
   hb_buffer_set_direction (hb_buffer,HB_DIRECTION_LTR);
   hb_buffer_set_script (hb_buffer, HB_SCRIPT_LATIN);
   hb_buffer_set_language (hb_buffer,hb_language_from_string ("en",-1));


   hb_shape (hb_font,hb_buffer,NULL,0);
   
// the things now is done 
 printf ("\n the all setting has been done and shaping is done \n");
 // we get the amount of glyph generated 
 unsigned int glyph_count;
 hb_glyph_info_t * glyph_info=hb_buffer_get_glyph_infos (hb_buffer,&glyph_count);

 hb_glyph_position_t *glyph_pos=hb_buffer_get_glyph_positions (hb_buffer,&glyph_count);
 // pen position of just what advanced_width
  static double pen_x=0;


 for (int i=0; i<glyph_count; i++) {
     // let get the id of the glyph 
     hb_codepoint_t glyph_id=glyph_info[i].codepoint;



     printf ("\n the glp data position infos \n");
     printf ("\n the glyph id is :%u\n",glyph_id);


     printf ("\n the x advance :%f\n",glyph_pos[i].x_advance/64.0);
     printf ("\n the y advance :%f\n",glyph_pos[i].y_advance/64.0);
     printf ("\n the x offset  :%d\n",glyph_pos[i].x_offset);
     printf ("\n the y offset  :%d\n",glyph_pos[i].y_offset);
 
     pen_x= pen_x+glyph_pos[i].x_advance/64.0;

     printf ("\n the holizontol pen position is :%f",pen_x);
     



     



 }

   printf ("\n the library has been initlized \n");


   hb_buffer_destroy (hb_buffer);

   hb_font_destroy (hb_font);



   

}



