
#pragma once 

#include<ft2build.h>
#include FT_FREETYPE_H

// AND THEN WE CREATE THE FONT WHICH IS GLOBAL 
typedef struct {

    FT_Library library;
    FT_Face    face ;

}Font;

 int free_type_init (Font *font,char * pathname,unsigned int pixel_size);
 

