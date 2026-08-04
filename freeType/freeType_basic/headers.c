// in free type we have to include the header file which help us to build the project and also it include the 
// header we can use for further transformations for te:
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

int main () {
FT_Library Library;
FT_Face    face;


int error=FT_Init_FreeType (&Library);

if(error==FT_Err_Ok) {

   // the libray created 
   printf ("\n the libray handle has been initilized or created !\n");

   int error1=FT_New_Face (Library, "/usr/share/fonts/truetype/ubuntu/Ubuntu-L.ttf",0,&face);
   printf ("error code is :%d",error1);

  if (error1==FT_Err_Ok) {
    printf ("\n the file could be opened and read  \n");
    printf ("the number of font foramt is :%ld",face->num_faces);

    
  }
  else if (error1==FT_Err_Unknown_File_Format){
    printf ("\n the file has been found but can not be opened !!!\n");





  }
  else {

printf ("the file format is unknown  !!");

 }

 }


}


 
