#include "ft_init.h"


int main (){

    fontContext fontConte;


freetype_init (&fontConte);

// accessing the face data 
// we start with the total amount of number of glphy which are in the file we have 
// included 
printf ("\n the number of the glyph found in the file are \n %ld \n",fontConte.face->num_glyphs);
printf ("\n the number of font flags which can be used within the files are :%#lb\n",fontConte.face->face_flags);
printf ("\n the adding the number of square of EM To track them in deep : \n %hu pixel per EMSquare(ppem )",fontConte.face->units_per_EM);
// set the character size this was mean that at creation of handle or object which or instance of face 
//setting the current positions 
int error2= FT_Set_Char_Size (fontConte.face, 0, 16*64, 300,300);
if (error2==FT_Err_Ok) {

    printf ("\n the character size has been set successfully !!! \n");



}
else {

    printf ("failed to initilzed ");



}
// setting the character size 
int error4= FT_Set_Pixel_Sizes (
        fontConte.face,
        0,
        16

        );

if (error4==FT_Err_Ok) {


    printf("the pixel size has been set on the screen successfully!!!!\n");


}
else {

    printf ("failed to loead the or to re size the character according to the pixel!! \n");


}






}
