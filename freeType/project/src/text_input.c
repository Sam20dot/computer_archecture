#include "../includes/text_input.h"

void char_callback(GLFWwindow *window, unsigned int charcode) {
    int glyph_index = FT_Get_Char_Index(font.face, charcode);
    if (glyph_index == 0) {
        printf("There is no glyph for the text: %c\n", charcode);
        return;
    }

    // 1. Use FT_LOAD_RENDER to generate bitmap pixels
    int error = FT_Load_Glyph(font.face, glyph_index, FT_LOAD_RENDER);
    if (error != FT_Err_Ok) {
        printf("Failed to load char into slot: %u (Error: %d)\n", charcode, error);
        return; // 2. Return immediately on failure
    }

    FT_GlyphSlot slot = font.face->glyph;

    if (slot->bitmap.buffer == NULL || slot->bitmap.width == 0) {
        return;
    }

    printf("Glyph '%c' (%u) loaded successfully! Size: %dx%d\n", 
            (char)charcode, charcode, slot->bitmap.width, slot->bitmap.rows);
}
