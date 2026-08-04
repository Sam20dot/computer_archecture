// this is the file for initilizing the files
#pragma once 
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H
#include <stdio.h>


typedef struct {

    FT_Library library;
    FT_Face    face;

}fontContext;



void freetype_init (fontContext *fontC);

