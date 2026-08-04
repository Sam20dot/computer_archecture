#include <freetype2/ft2build.h>
#include FT_FREETYPE_H
#include <stdio.h>

// then we are about to initilize the library
int main() {
  FT_Library library;
  FT_Face face;

  int error = FT_Init_FreeType(&library);
  if (error == FT_Err_Ok) {

    printf("\n the library has been initilized ");

  } else {

    printf("failed to initlized the library ");
    return -1;
  }
  char *pathname = "/usr/share/fonts/truetype/ubuntu/UbuntuSans[wdth,wght].ttf";

  int error1 = FT_New_Face(library, pathname, 0, &face);
  if (error1 == FT_Err_Ok) {
    printf("\n the file has been created and initlized ");

  } else if (error1 == FT_Err_Unknown_File_Format) {

    printf("the file can be opened but is not supported ");
  } else {

    printf("\n the file is broken");
  }
  // then we are about to access the whole face data
  // they are all contains within the object called
  printf("\n the face is %ld ", face->num_glyphs);
  printf("\n the face flag is :%#lb,%zu", face->face_flags,
         sizeof(face->face_flags));
  printf("\n the unit per em square is :%hu\n ", face->units_per_EM);


  // let go on the avaliable size on the screen 
  
 }
