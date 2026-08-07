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
    
    



}
