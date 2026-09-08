#pragma once

#include <GLFW/glfw3.h>
#include<stdio.h>


void error_callback(int error,const char * discritpion);
int initilize_glfw ();
GLFWwindow *create_window (char * windowName);
int close_window (GLFWwindow* window);

