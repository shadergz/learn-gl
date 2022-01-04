/*
 *  Source code written by Gabriel Correia
*/

#include <iostream>

#include <GLFW/glfw3.h>

constexpr GLint WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;

static GLfloat current_colors[3];

int main (int argc, char **argv)
{
    GLFWwindow *main_window;

    glfwInit ();

    /* Creating a window to render into it */
    main_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 
        "Color 01", nullptr, nullptr);
    glfwMakeContextCurrent (main_window);

    while (! glfwWindowShouldClose (main_window)) {

        /* Collecting the current color buffer */
        glGetFloatv (GL_CURRENT_COLOR, current_colors);
        std::printf ("Current colors R: %f G: %f B: %f\n", 
            current_colors[0], current_colors[1], current_colors[2]);

        glClear (GL_COLOR_BUFFER_BIT);

        glBegin (GL_TRIANGLES);
        glColor3f (1.0f, 0.0f, 0.0f);

        glVertex2f (-0.5f, 0.0f);
        glVertex2f (0.0f, 0.5f);
        glVertex2f (0.5f, 0.0f);
        glEnd ();

        glfwSwapBuffers (main_window);
        glfwPollEvents ();
    }

    glfwDestroyWindow (main_window);
    glfwTerminate ();

    return 0;
}

