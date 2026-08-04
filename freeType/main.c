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
// then here we  are going to convert the character into the glyph indexs
// let play with it 

int glyph_index=FT_Get_Char_Index(fontConte.face,64);
printf ("\n the glyph converted values is :%d char is :%c ",glyph_index,65);

// then we are going to load the font part into the slot within the memory 
int error5=FT_Load_Glyph (fontConte.face,glyph_index,FT_LOAD_DEFAULT);
if (error5==FT_Err_Ok) {
printf ("\n the values has been moved into a slot which is now we we can go on step of rendering it \n");


}
else {
    printf ("\n failed to load those file into a slot or the container which contains one values \n");


}

//then we are going to see the fomrt which has been used to incored it 
printf ("\n the format used for incording the values is for slot  :%du \n",fontConte.face->glyph->format);

// then now we can do the amazing things for the last time for rendering this images 
int error6=FT_Render_Glyph (
        fontConte.face->glyph,
        FT_RENDER_MODE_NORMAL
        );
if (error6==FT_Err_Ok) {
    printf ("the image has been rendered very well so that i can use it ");
}

printf ("\n access to the bit map where they are stored before seeing me to put them on screen \n ");
printf ("\n the let    bitmap %d\n",fontConte.face->glyph->bitmap_left);
printf ("\n the right  bitmap %d\n",fontConte.face->glyph->bitmap_top);




}
