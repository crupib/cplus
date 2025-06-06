#include <iostream>
//
//  main.cpp
//  Opengl Test
//
//  Created by William Crupi on 9/10/23.
//

#include <iostream>
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

int main(int argc, const char* argv[]) {
    // insert code here...
    int screenWidth, screenHeight;
    const GLint WIDTH = 800, HEIGHT = 600;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
 //   glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    glViewport(0, 0, screenWidth, screenHeight);
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();

    return EXIT_SUCCESS;
}