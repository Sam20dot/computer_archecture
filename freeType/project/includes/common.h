#pragma once

#define SOKOL_GLCORE
#include "../libs/sokol/sokol_gfx.h"
#include "../libs/sokol/sokol_log.h"

//2. imprementation of glfw for helping me creating the window 
#include <GLFW/glfw3.h>

// freetype for helping me to do all other things like 
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H
#include <stdio.h>

typedef struct {
FT_Library library;
FT_Face    face;


}fontInit;
extern fontInit font ;



