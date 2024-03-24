//
//  main.cpp
//  GLFW opengl
//
//  Created by 조혜형 on 2024/03/24.
//

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
const GLint WIDTH  =  800, HEIGHT = 600;

// The Main function required  options for GLFW
int main() {
    // Init  GLFW
    glfwInit();
    
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    // Create a GLFWwindow object that we can use for GLFW's  functions
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Learn Opengl", nullptr, nullptr);
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if(nullptr == window)
    {
        std::cout << "Failed to  createGLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    
    
    if(GLEW_OK !=  glewInit()) {
        std::cout << "Failed to  init" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}
