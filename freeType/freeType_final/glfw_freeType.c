#define SOKOL_IMPL
#define SOKOL_GLCORE
#include "./libs/sokol/sokol_gfx.h"
#include "./libs/sokol/sokol_log.h"

#include <ft2build.h>
#include FT_FREETYPE_H
#include <GLFW/glfw3.h>




typedef struct {

    FT_Library library;
    FT_Face    face;
}Font;
  
Font font;




void error_callback (int Error,const char *discription) {

    fprintf (stderr,"the error happened :%s",discription);
}

void char_callback (GLFWwindow *window,unsigned int codeprint ) {
    //  we get that character code and then finds its corresponding values 
    int glyph_index=FT_Get_Char_Index (font.face,codeprint);
    printf ("the character values is :%c and its glyph index is :%d\n",codeprint,glyph_index);
    if (FT_Load_Glyph(font.face,glyph_index,FT_LOAD_DEFAULT)==FT_Err_Ok) {
        FT_Render_Glyph (font.face->glyph,FT_RENDER_MODE_NORMAL);
        
        FT_GlyphSlot slot=font.face->glyph;

        printf ("the glyph bitmap has been loaded  within the memory !!!\n");
        printf ("the character is :%c \nthe slot bit map widith:%d \n the slot bit map rows :%d\n",codeprint,slot->bitmap.width,slot->bitmap.rows);
        
    }
    fflush (stdout);
}


int main  () {
    // glfw or the frameworks of the graphic library part which must be seen over here 
    glfwSetErrorCallback (error_callback);
    if (!glfwInit ()) {
        printf ("\nfailed to initlized \n");
    }

    // window creation 
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    // WINDOW CREATION 
    GLFWwindow *window =glfwCreateWindow (1200,800,"sam Editor",NULL,NULL);
    if (!window) {
        printf  ("\n failed to craete window ");
    }
    
    // creating the context of the window 
    glfwMakeContextCurrent (window);

    // definition of freetype and its declarations 

      char *pathname= "/usr/share/fonts/truetype/ubuntu/UbuntuMono-RI.ttf";
  
    int libraryInit= FT_Init_FreeType (&font.library);

    if (libraryInit==FT_Err_Ok) {
        printf ("\n the library initlized ");
    }
    int faceInit =FT_New_Face (font.library,pathname,0,&font.face);
    if (faceInit==FT_Err_Ok) {

        printf  ("\n the face has been created\n ");

    }

    // then listen to the handle or callback we have created 
    //
    printf ("\n_____ WELLCOME ON THE COMBINATION OF GLFW AND FREETYPE _____\n");
    printf ("\n the glfw listen to a character code and then freeType tell me its glyph index from memory \n\n");

    // setting up sokol_gfx to help me render my character on the screen 
    sg_setup(&(sg_desc) {
            .environment= {

             .defaults= {

               .color_format=SG_PIXELFORMAT_RGBA8,
               .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
               .sample_count=1,

             }
            }


            });
    // then we create the actions here and then we will do 
    sg_pass_action pass_action={
        .colors[0]={
            .load_action=SG_LOADACTION_CLEAR,
            .clear_value={0.1f,0.2f,0.4f,0.3f}

            
        }
    };


    glfwSetCharCallback (window,char_callback);

    while (!glfwWindowShouldClose (window)) {
        // i need the window hiegth
        int height,width;
        glfwGetWindowSize (window ,&width,&height);


        sg_begin_pass (&(sg_pass) {
                .swapchain={
                 .color_format=SG_PIXELFORMAT_RGBA8,
                 .depth_format=SG_PIXELFORMAT_DEPTH_STENCIL,
                 .width=width,
                 .height=height,
                 .sample_count=1


                },
                .action=pass_action

                });
        sg_end_pass ();
        sg_commit ();


        glfwPollEvents();

        glfwSwapBuffers (window);






    }

    sg_shutdown ();

    glfwDestroyWindow (window);
    glfwTerminate ();

  


    


}
