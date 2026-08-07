#include <ft2build.h>
#include FT_FREETYPE_H

// then we start by creating the library 
int main  () {

    FT_Library library;
    FT_Face    face   ;
    int libraryInit= FT_Init_FreeType (&library);
    if (libraryInit==FT_Err_Ok)  {

        printf ("\nlibrary initilized\n ");

    }

    // then we initlize the face 
    int faceInit = FT_New_Face (library,"/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf",0,&face);
    if (faceInit==FT_Err_Ok) {

        printf ("\n new face has been created \n");

    }
    else if (faceInit==FT_Err_Unknown_File_Format) {

        printf ("\n the format found but it is not supported \n");

    }
    else {
        printf ("\n the font is problem is not available \n");

    }
    printf  ("\n the number of the glyph which is in this file is :%ld\n",face->num_glyphs);
    printf  ("\n the flags which discribes the values within that file :%#lb\n",face->face_flags);
    printf  ("\n the units per EM square like the units it covers in : %d \n",face->units_per_EM);

// zero mean that the same size as the width we start with width, height and then we end up with resoultion 
// which are measured in dot per inch 
//
 //   int setCharSize= FT_Set_Char_Size (face,0,16*64,300,300) ;
  //  if (setCharSize==FT_Err_Ok )  {

  //      printf  ("\n the size has been set ");

  //  }

  /// then we set the resolutions within that part 

  int setPixelSize = FT_Set_Pixel_Sizes (face,0,16);
  if (setPixelSize==FT_Err_Ok) {

      printf  ("\n we have set the pixel size as 16px and i know they happened \n");
  }

  // now we are going to get the glyph index of a given valuues on my machine so that they cane be linked in what we call 
  // character map which is containing the index points to the glyph places in memory 
  int glyph_index=FT_Get_Char_Index (face,'A');

  printf ("the character A its locations or index is :%d\n",glyph_index);

// then we are going to 
    
    



}
