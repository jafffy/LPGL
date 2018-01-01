#include <GLFW/glfw3.h>
#include <vector>

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

    std::vector<float> backBuffer;

    for (int i = 0; i < width * height * 2 * 2; ++i)
    {
        backBuffer.push_back(0.5f);
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glRasterPos2d(-1.0, -1.0);
        glDrawPixels(width * 2, height * 2, GL_RED,
        GL_FLOAT, backBuffer.data());

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}