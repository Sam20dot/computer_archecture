
#include <ft2build.h>
#include FT_FREETYPE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <map>



void error_callback (int error,const char *discr) {

 std::cout <<stderr<<"error"<<discr;


} 


int main () {
glfwSetErrorCallback (error_callback);

glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

GLFWwindow *window= glfwCreateWindow (1200,800,"sam_editor,",NULL,NULL);
if (window==NULL) {
    std::cout << " the window failed to initilize ";
    return -1;


}

glfwMakeContextCurrent (window);

// and then we initilize the glad so that we can get the locations of opengl on our machine 
// in memory
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

        std::cout << "failed to initilize glad";
        return -1;
    }

// then we initlize the freeType 
FT_Library library;
FT_Face face;

if (FT_Init_FreeType (&library)) {
    std::cout << "ERROR:: FREETYPE:could not initlize freetype library";
    
}
// and then we create the face 
if (FT_New_Face (library,"/usr/share/fonts/truetype/ubuntu/UbuntuMono[wght].ttf",0,&face))  {
    std::cout << "ERROR:FREETYPE;failed to create a new face class";
    return -1;
    }

// then we set the character size 
FT_Set_Pixel_Sizes (face,0,48);

// then we load a given font into a slot 
if (FT_Load_Char (face,'X',FT_LOAD_RENDER)) {
    std::cout << "failed to load a character into a slot ";


    }

// then let create the structure to render that values on the screen 
struct Character {

    unsigned int characterID;
    glm::ivec2  size;
    glm::ivec2  bearing;
     long int advance;

};

std::map <char, Character>characters;
glPixelStorei (GL_UNPACK_ALIGNMENT,1);

for (unsigned char c=0; c<128;c++) {

    if (FT_Load_Char (face,c,FT_LOAD_RENDER)) {
        std::cout <<"failed to loead the character glyph";
        continue;

    }
  
    // we design the texture elements 
    unsigned int texture;
    glGenTextures (1,&texture);
    glBindTexture (GL_TEXTURE_2D,texture);
    glTexImage2D (GL_TEXTURE_2D,0,GL_RED,face->glyph->bitmap.width,
            face->glyph->bitmap.rows,0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
            
            );
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    Character character = {
        texture,
        glm::ivec2(face->glyph->bitmap.width,face->glyph->bitmap.rows),
        glm::ivec2(face->glyph->bitmap_left,face->glyph->bitmap_top),

        // the last one is advance
        face->glyph->advance.x
    };
    characters.insert (std::pair <char,Character>(c,character));


// once we finish to processs or freetype character we do the following 



}


// first we create shaders 
const char *vertexShaders =
"#version 330 core\n"
"layout (location=0) in vec4 vertex;\n"
"out vec2 textCoord;\n"
"void main () {\n"
"gl_Position=projection*vec4(vertex.xy,0.0,1.0);\n"
"textCoord=vertex.zw;\n"
"}\0";

// then create shaders 
unsigned int shaderId;
shaderId=glCreateShader (GL_VERTEX_SHADER);
glShaderSource (shaderId,1,&vertexShaders,NULL);

// then compile them here 
glCompileShader (shaderId);

// and then we deal with fragment shaders also 
const char * fragmentShader = 
"#version 330 core\n"
"in vec2 textCoord;\n"
"out vec4 color;\n"
"uniform sample2D text;\n"
"uniform vec3 textColor;\n"
"void main () {\n"
"vec4 sampled=vec4(1.0,1.0,1.0,texture (text,textCoord).r);\n"
"color=vec4(textColor,1.0)*sampled;\n"
"}\n";


unsigned int fragmentId;
fragmentId =glCreateShader (GL_FRAGMENT_SHADER);
glShaderSource (fragmentId,1,&fragmentShader,NULL);
glCompileShader (fragmentId);


unsigned int shaderProgram;
shaderProgram=glCreateProgram ();
glAttachShader (shaderProgram,shaderId);
glAttachShader (shaderProgram,fragmentId);

glLinkProgram (shaderProgram);

// then we delete shaders becouse we dont need them now 
glDeleteShader(shaderId);
glDeleteShader(fragmentId);

glEnable (GL_BLEND);
glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);


unsigned int VAO, VBO;
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);
glBindVertexArray(VAO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
glBindBuffer(GL_ARRAY_BUFFER, 0);
glBindVertexArray(0);

void RenderText(Shader &s, std::string text, float x, float y, float scale, glm::vec3 color)
{
    // activate corresponding render state	
    s.Use();
    glUniform3f(glGetUniformLocation(s.Program, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    // iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = Characters[*c];

        float xpos = x + ch.Bearing.x * scale;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;
        // update VBO for each character
        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.textureID);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64)
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
float ypos = y - (ch.Size.y - ch.Bearing.y);

while (!glfwWindowShouldClose (window)) {

    glViewport (0,0,1200,800);
    g;

}



}

