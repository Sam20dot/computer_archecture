#include <freetype2/ft2build.h>
#include <stdio.h>
#include FT_FREETYPE_H

int main() {

  FT_Library library;
  FT_Face face;

  // library intilizations and see if it works
  int error = FT_Init_FreeType(&library);
}
