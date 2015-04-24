#include <GLFW/glfw3.h>

#include <cstdio>


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    printf("success 0\n");

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    printf("success 1\n");

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    printf("success 2\n");

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    printf("success 3\n");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}