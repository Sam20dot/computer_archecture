#include "ft_init.h"



void freetype_init(fontContext *fontC) {
  // initlize the library
  //
  int error = FT_Init_FreeType(&fontC->library);
  if (error == FT_Err_Ok) {

    printf("\n the library for free type it has been intilized correctly \n");
  }
  // then the pathname
  char *pathname = "/usr/share/fonts/truetype/ubuntu/UbuntuSansMono[wght].ttf";


      // then create a new face from for each categores on the sceen
      int error1 = FT_New_Face(fontC->library, pathname, 0, &fontC->face);
  if (error1 == FT_Err_Ok) {

    printf("\n the fie loaded,opened and read will be used for father useage");
  } else if (error1 == FT_Err_Unknown_File_Format) {

    printf("the file is found but the format is not supported !!\n");

  }
} 
