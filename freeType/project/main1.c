#include "./includes/poly_init.h"
#include "./includes/text_input.h"



 fontInit font;

int main () {
   
     char *pathname="/usr/share/fonts/truetype/ubuntu/UbuntuMono-R.ttf";


glfw_Init ();
// then make the context 
glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR,3);
glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR,3);
glfwWindowHint (GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

// THEN CREATE WINDOW 
GLFWwindow *window = glfwCreateWindow (1200,800, "Poly_Lab_editor",NULL,NULL);
glfwMakeContextCurrent (window);
// initlize the sokol 
sokol_init ();
// font type 
freeType_init(&font, pathname);


glfwSetCharCallback (window,char_callback);

// then let make it open like window should not close until we click like control +c 

while (!glfwWindowShouldClose (window)) {

    glfwPollEvents ();


}
sg_shutdown ();
glfwDestroyWindow (window);
glfwTerminate ();
printf ("\n woooooooo after almost 7 hours learning \n and doing deep learning \n i can combine three things and initlize them together \n Thank you God \n to allow it to happen \n");



}
