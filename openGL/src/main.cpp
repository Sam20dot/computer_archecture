#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback (GLFWwindow *window,int width,int height) {

glViewport (0,0,width,height);
}

void processInput (GLFWwindow *window) {

    if (glfwGetKey(window,GLFW_KEY_ESCAPE==GLFW_PRESS)) {

    glfwSetWindowShouldClose (window,true);
    
    std::cout << "the character is :"<<GLFW_KEY_1;
    }


}


int main () {

    if (!glfwInit()) {

        std::cout << " the glfw failed to initiate !!\n";
        return -1;


    }

    // then we make the options 
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window =glfwCreateWindow (1200,800,"sam_editor",NULL,NULL);
    if (window==NULL) {

        std::cout << "failed to create window ";
        return -1;


    }
    glfwMakeContextCurrent (window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

        std::cout << "failed to initilize glad";
        return -1;


    }
    // we can set the view point 
    glViewport (0,0,800,600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    float vertices[]= {
        -0.5f,-0.5f,0.0f,
        0.5f ,-0.5f,0.0f,
        0.0f , 0.5f,0.0f

    };

    // then we create what we call vertex buffer object, as object that can store tha large amount of the things 
    // and this has its unique id as so that the shaders can deal with it in eaiser way 
    unsigned int VBO;

    // then we also have to register the vertex array object which help us to track the record the position 
    // and the values we have reached on 
    unsigned int VAO;
    glGenVertexArrays (1,&VAO);
    glBindVertexArray (VAO);

    // THAT HELP US TO GENERATE THE ID
    glGenBuffers(1,&VBO);

    // so now we have id of the object but we dont know its values and gpu does not know what will cames with it 
    // so let try to tell its type of vertex 
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    // now we are about to copy all data into the data memory 
    glBufferData (GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);

    // the shadres the one we are dealing with is vertex shaders 
    const char * vertexShaderSource= 
        "#version 330 core \n"
        "layout (location=0) in vec3 aPos;\n"
        "void main () {\n"
        "gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
        "}\0";

    // then we create an id for vertex buffer we have to deal with it in gooda ways 
    unsigned int vertexShader;
    vertexShader= glCreateShader (GL_VERTEX_SHADER);
    glShaderSource (vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader (vertexShader);

    const char *fragmentShaderSource =
        "#version 330 core \n"
        "out vec4 FragColor;\n"
        "void main () {\n"
        "FragColor=vec4 (0.6f,0.3f,0.4f,1.0f);\n"
        "}\0";


    
    unsigned int fragmentShader;
    fragmentShader=glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fragmentShader,1,&fragmentShaderSource,NULL );
    glCompileShader (fragmentShader);


    // then now we are about to link them here 
    unsigned int shaderProgram ;
    shaderProgram=glCreateProgram ();
    glAttachShader (shaderProgram,vertexShader);
    glAttachShader (shaderProgram,fragmentShader);
    glLinkProgram (shaderProgram);

    /// after linking we can delete all shaders 
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
   
glVertexAttribPointer (0,3,GL_FLOAT,GL_FALSE,3*sizeof (float),(void*)0);
// then for now we arbout to enable the attributes 
glEnableVertexAttribArray (0);

    // then compile them also 
    
    // we call this the render loop 
    
    while (!glfwWindowShouldClose (window)) {
       
        

       
                    


        glClearColor (0.3f,0.4f,0.1f,0.6f);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        processInput (window);



        glfwSwapBuffers(window);
        glfwPollEvents ();
                
      

    }
// then we terminate that 
glfwTerminate ();
return 0;


}
