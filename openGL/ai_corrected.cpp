#include <ft2build.h>
#include FT_FREETYPE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// ------------------------------------------------------------
// Error callback
// ------------------------------------------------------------

void error_callback(int error, const char* description)
{
    std::cerr << "GLFW ERROR " << error << ": "
              << description << std::endl;
}


// ------------------------------------------------------------
// Character structure
// ------------------------------------------------------------

struct Character
{
    unsigned int textureID;

    glm::ivec2 size;

    glm::ivec2 bearing;

    long int advance;
};


// ------------------------------------------------------------
// Global character map
// ------------------------------------------------------------

std::map<char, Character> characters;


// ------------------------------------------------------------
// OpenGL objects used for rendering text
// ------------------------------------------------------------

unsigned int VAO;
unsigned int VBO;


// ------------------------------------------------------------
// Shader creation helper
// ------------------------------------------------------------

unsigned int compileShader(
    GLenum type,
    const char* source
)
{
    unsigned int shader = glCreateShader(type);

    glShaderSource(
        shader,
        1,
        &source,
        nullptr
    );

    glCompileShader(shader);


    // Check compilation
    int success;
    char infoLog[512];

    glGetShaderiv(
        shader,
        GL_COMPILE_STATUS,
        &success
    );

    if (!success)
    {
        glGetShaderInfoLog(
            shader,
            512,
            nullptr,
            infoLog
        );

        std::cerr
            << "SHADER COMPILATION ERROR:\n"
            << infoLog
            << std::endl;
    }

    return shader;
}


// ------------------------------------------------------------
// Render text
// ------------------------------------------------------------

void RenderText(
    unsigned int shaderProgram,
    const std::string& text,
    float x,
    float y,
    float scale,
    glm::vec3 color
)
{
    glUseProgram(shaderProgram);


    // --------------------------------------------------------
    // Set text color
    // --------------------------------------------------------

    int colorLocation =
        glGetUniformLocation(
            shaderProgram,
            "textColor"
        );

    glUniform3f(
        colorLocation,
        color.x,
        color.y,
        color.z
    );


    // --------------------------------------------------------
    // Tell OpenGL to use texture unit 0
    // --------------------------------------------------------

    glActiveTexture(GL_TEXTURE0);


    // --------------------------------------------------------
    // Bind text VAO
    // --------------------------------------------------------

    glBindVertexArray(VAO);


    // --------------------------------------------------------
    // Render every character
    // --------------------------------------------------------

    for (char c : text)
    {
        Character ch = characters[c];


        // Position of the glyph

        float xpos =
            x + ch.bearing.x * scale;

        float ypos =
            y - (ch.size.y - ch.bearing.y) * scale;


        // Size of glyph

        float w =
            ch.size.x * scale;

        float h =
            ch.size.y * scale;


        // ----------------------------------------------------
        // Two triangles making the character quad
        // ----------------------------------------------------

        float vertices[6][4] =
        {
            {
                xpos,
                ypos + h,
                0.0f,
                0.0f
            },

            {
                xpos,
                ypos,
                0.0f,
                1.0f
            },

            {
                xpos + w,
                ypos,
                1.0f,
                1.0f
            },

            {
                xpos,
                ypos + h,
                0.0f,
                0.0f
            },

            {
                xpos + w,
                ypos,
                1.0f,
                1.0f
            },

            {
                xpos + w,
                ypos + h,
                1.0f,
                0.0f
            }
        };


        // ----------------------------------------------------
        // Bind glyph texture
        // ----------------------------------------------------

        glBindTexture(
            GL_TEXTURE_2D,
            ch.textureID
        );


        // ----------------------------------------------------
        // Update VBO
        // ----------------------------------------------------

        glBindBuffer(
            GL_ARRAY_BUFFER,
            VBO
        );

        glBufferSubData(
            GL_ARRAY_BUFFER,
            0,
            sizeof(vertices),
            vertices
        );


        // ----------------------------------------------------
        // Draw the character
        // ----------------------------------------------------

        glDrawArrays(
            GL_TRIANGLES,
            0,
            6
        );


        // ----------------------------------------------------
        // Move cursor to next character
        //
        // FreeType advance is stored in 1/64 pixels
        // ----------------------------------------------------

        x +=
            (ch.advance >> 6) * scale;
    }


    glBindVertexArray(0);

    glBindTexture(
        GL_TEXTURE_2D,
        0
    );
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    // --------------------------------------------------------
    // GLFW
    // --------------------------------------------------------

    glfwSetErrorCallback(error_callback);


    if (!glfwInit())
    {
        std::cerr
            << "Failed to initialize GLFW"
            << std::endl;

        return -1;
    }


    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MAJOR,
        3
    );

    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MINOR,
        3
    );

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        GLFW_OPENGL_CORE_PROFILE
    );


    // --------------------------------------------------------
    // Create window
    // --------------------------------------------------------

    GLFWwindow* window =
        glfwCreateWindow(
            1200,
            800,
            "sam_editor",
            nullptr,
            nullptr
        );


    if (window == nullptr)
    {
        std::cerr
            << "The window failed to initialize"
            << std::endl;

        glfwTerminate();

        return -1;
    }


    glfwMakeContextCurrent(window);


    // --------------------------------------------------------
    // GLAD
    // --------------------------------------------------------

    if (!gladLoadGLLoader(
            (GLADloadproc)glfwGetProcAddress))
    {
        std::cerr
            << "Failed to initialize GLAD"
            << std::endl;

        glfwDestroyWindow(window);
        glfwTerminate();

        return -1;
    }


    std::cout
        << "OpenGL: "
        << glGetString(GL_VERSION)
        << std::endl;


    // --------------------------------------------------------
    // FreeType initialization
    // --------------------------------------------------------

    FT_Library library;

    if (FT_Init_FreeType(&library))
    {
        std::cerr
            << "ERROR::FREETYPE: Could not initialize "
               "FreeType library"
            << std::endl;

        glfwDestroyWindow(window);
        glfwTerminate();

        return -1;
    }


    // --------------------------------------------------------
    // Load font
    // --------------------------------------------------------

    FT_Face face;

    if (FT_New_Face(
            library,
            "/usr/share/fonts/truetype/ubuntu/UbuntuMono[wght].ttf",
            0,
            &face))
    {
        std::cerr
            << "ERROR::FREETYPE: Failed to create face"
            << std::endl;

        FT_Done_FreeType(library);

        glfwDestroyWindow(window);
        glfwTerminate();

        return -1;
    }


    // --------------------------------------------------------
    // Font size
    // --------------------------------------------------------

    if (FT_Set_Pixel_Sizes(
            face,
            0,
            48))
    {
        std::cerr
            << "ERROR::FREETYPE: Failed to set pixel size"
            << std::endl;
    }


    // --------------------------------------------------------
    // OpenGL texture alignment
    // --------------------------------------------------------

    glPixelStorei(
        GL_UNPACK_ALIGNMENT,
        1
    );


    // --------------------------------------------------------
    // Load ASCII characters
    // --------------------------------------------------------

    for (unsigned char c = 0; c < 128; c++)
    {
        if (FT_Load_Char(
                face,
                c,
                FT_LOAD_RENDER))
        {
            std::cerr
                << "ERROR::FREETYPE: Failed to load glyph "
                << static_cast<int>(c)
                << std::endl;

            continue;
        }


        // ----------------------------------------------------
        // Create texture
        // ----------------------------------------------------

        unsigned int texture;

        glGenTextures(
            1,
            &texture
        );

        glBindTexture(
            GL_TEXTURE_2D,
            texture
        );


        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );


        // ----------------------------------------------------
        // Texture parameters
        // ----------------------------------------------------

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_WRAP_S,
            GL_CLAMP_TO_EDGE
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_WRAP_T,
            GL_CLAMP_TO_EDGE
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_MIN_FILTER,
            GL_LINEAR
        );

        glTexParameteri(
            GL_TEXTURE_2D,
            GL_TEXTURE_MAG_FILTER,
            GL_LINEAR
        );


        // ----------------------------------------------------
        // Store character information
        // ----------------------------------------------------

        Character character =
        {
            texture,

            glm::ivec2(
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows
            ),

            glm::ivec2(
                face->glyph->bitmap_left,
                face->glyph->bitmap_top
            ),

            face->glyph->advance.x
        };


        characters.insert(
            std::pair<char, Character>(
                c,
                character
            )
        );
    }


    // We don't need the face anymore
    FT_Done_Face(face);

    // We don't need FreeType anymore
    FT_Done_FreeType(library);


    // ========================================================
    // VERTEX SHADER
    // ========================================================

    const char* vertexShaderSource =
        "#version 330 core\n"

        "layout (location = 0) in vec4 vertex;\n"

        "out vec2 textCoord;\n"

        "uniform mat4 projection;\n"

        "void main()\n"
        "{\n"

        "    gl_Position = "
        "projection * vec4(vertex.xy, 0.0, 1.0);\n"

        "    textCoord = vertex.zw;\n"

        "}\n";


    // ========================================================
    // FRAGMENT SHADER
    // ========================================================

    const char* fragmentShaderSource =
        "#version 330 core\n"

        "in vec2 textCoord;\n"

        "out vec4 color;\n"

        "uniform sampler2D text;\n"

        "uniform vec3 textColor;\n"

        "void main()\n"
        "{\n"

        "    float alpha = "
        "texture(text, textCoord).r;\n"

        "    color = vec4(textColor, alpha);\n"

        "}\n";


    // --------------------------------------------------------
    // Compile shaders
    // --------------------------------------------------------

    unsigned int vertexShader =
        compileShader(
            GL_VERTEX_SHADER,
            vertexShaderSource
        );


    unsigned int fragmentShader =
        compileShader(
            GL_FRAGMENT_SHADER,
            fragmentShaderSource
        );


    // --------------------------------------------------------
    // Create shader program
    // --------------------------------------------------------

    unsigned int shaderProgram =
        glCreateProgram();


    glAttachShader(
        shaderProgram,
        vertexShader
    );

    glAttachShader(
        shaderProgram,
        fragmentShader
    );


    glLinkProgram(shaderProgram);


    // --------------------------------------------------------
    // Check program linking
    // --------------------------------------------------------

    int success;

    char infoLog[512];

    glGetProgramiv(
        shaderProgram,
        GL_LINK_STATUS,
        &success
    );


    if (!success)
    {
        glGetProgramInfoLog(
            shaderProgram,
            512,
            nullptr,
            infoLog
        );

        std::cerr
            << "SHADER PROGRAM LINK ERROR:\n"
            << infoLog
            << std::endl;
    }


    // --------------------------------------------------------
    // Shaders can now be deleted
    // --------------------------------------------------------

    glDeleteShader(vertexShader);

    glDeleteShader(fragmentShader);


    // ========================================================
    // PROJECTION
    // ========================================================

    glm::mat4 projection =
        glm::ortho(
            0.0f,
            1200.0f,
            0.0f,
            800.0f
        );


    glUseProgram(shaderProgram);


    int projectionLocation =
        glGetUniformLocation(
            shaderProgram,
            "projection"
        );


    glUniformMatrix4fv(
        projectionLocation,
        1,
        GL_FALSE,
        &projection[0][0]
    );


    // --------------------------------------------------------
    // Texture sampler uses texture unit 0
    // --------------------------------------------------------

    int textureLocation =
        glGetUniformLocation(
            shaderProgram,
            "text"
        );


    glUniform1i(
        textureLocation,
        0
    );


    // ========================================================
    // BLENDING
    // ========================================================

    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );


    // ========================================================
    // VAO + VBO
    // ========================================================

    glGenVertexArrays(
        1,
        &VAO
    );

    glGenBuffers(
        1,
        &VBO
    );


    glBindVertexArray(VAO);


    glBindBuffer(
        GL_ARRAY_BUFFER,
        VBO
    );


    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(float) * 6 * 4,
        nullptr,
        GL_DYNAMIC_DRAW
    );


    glEnableVertexAttribArray(0);


    glVertexAttribPointer(
        0,
        4,
        GL_FLOAT,
        GL_FALSE,
        4 * sizeof(float),
        nullptr
    );


    glBindBuffer(
        GL_ARRAY_BUFFER,
        0
    );

    glBindVertexArray(0);


    // ========================================================
    // MAIN RENDER LOOP
    // ========================================================

    while (!glfwWindowShouldClose(window))
    {
        // ----------------------------------------------------
        // Clear screen
        // ----------------------------------------------------

        glClearColor(
            0.1f,
            0.1f,
            0.1f,
            1.0f
        );

        glClear(GL_COLOR_BUFFER_BIT);


        // ----------------------------------------------------
        // Render text
        // ----------------------------------------------------

        RenderText(
            shaderProgram,
            "Hello Sam!",
            50.0f,
            700.0f,
            1.0f,
            glm::vec3(
                1.0f,
                1.0f,
                1.0f
            )
        );


        RenderText(
            shaderProgram,
            "FreeType + OpenGL",
            50.0f,
            620.0f,
            0.8f,
            glm::vec3(
                0.8f,
                0.8f,
                0.8f
            )
        );


        // ----------------------------------------------------
        // Display frame
        // ----------------------------------------------------

        glfwSwapBuffers(window);


        // ----------------------------------------------------
        // Process keyboard/window events
        // ----------------------------------------------------

        glfwPollEvents();
    }


    // ========================================================
    // CLEANUP
    // ========================================================

    glDeleteVertexArrays(
        1,
        &VAO
    );

    glDeleteBuffers(
        1,
        &VBO
    );

    glDeleteProgram(
        shaderProgram
    );


    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
