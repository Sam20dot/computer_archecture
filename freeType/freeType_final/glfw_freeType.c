#include <ft2build.h>
#include FT_FREETYPE_H

typedef struct {

    FT_Library library;
    FT_Face    face;
}font;

int main  () {
    font font;
    char *pathname= "/usr/share/fonts/truetype/ubuntu/UbuntuMono-RI.ttf";
    int chara;




    int libraryInit= FT_Init_FreeType (&font.library);

    if (libraryInit==FT_Err_Ok) {
        printf ("\n the library initlized ");
    }
    int faceInit =FT_New_Face (font.library,pathname,0,&font.face);
    if (faceInit==FT_Err_Ok) {

        printf  ("\n the face has been created ");

    }
    while (1) {
    
        printf ("\n the character code \n");
        scanf  ("%d",&chara);

        // we get the character index 
        int glyph_index= FT_Get_Char_Index (font.face,chara);
        printf ("the character values is :%c and its code is :%d\n",chara,glyph_index);



    }


}
