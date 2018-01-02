#include <GL/lpgl.h>

#include <GLFW/glfw3.h>

#include <vector>

#include <cstdio>

int main(int argc, char** argv)
{
    GLFWwindow* window;

    if (!glfwInit())
    return -1;

    int width = 800, height = 600;

    window = glfwCreateWindow(width, height, "Hello", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    lpgl::lpglInit(800, 600);

    glClearColor(0, 0, 0.3f, 0.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glRasterPos2d(-1.0, -1.0);
        glDrawPixels(width * 2, height * 2, GL_RED,
                     GL_FLOAT, lpgl::lpglCommit());

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}