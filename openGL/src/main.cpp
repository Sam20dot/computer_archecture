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

    // we call this the render loop 
    
    while (!glfwWindowShouldClose (window)) {
        

        for (float i=0.0f; i<1; i+=0.0001){
        // then we add the color 
        glClearColor (i,0.4f,0.5f,0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        processInput (window);



        glfwSwapBuffers(window);
        glfwPollEvents ();
        }



    }
// then we terminate that 
glfwTerminate ();
return 0;


}
