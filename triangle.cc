/*
 *  Source code written by Gabriel Correia
*/

#include <iostream>

#include <GLFW/glfw3.h>

constexpr GLint WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;

int main (int argc, char **argv)
{
    GLFWwindow *main_window;

    /*  Initializing the support library to give us multi-plataform
     *  features like a window and input events handler 
    */
    glfwInit ();

    /* Creating a window to render into it */
    main_window = glfwCreateWindow (WINDOW_WIDTH, WINDOW_HEIGHT, 
        "Triangle", nullptr, nullptr);
    glfwMakeContextCurrent (main_window);

    while (! glfwWindowShouldClose (main_window)) {
        /* Time to render something */
        /* glClear (GL_COLOR_BUFFER_BIT); */

        glBegin (GL_TRIANGLES);

        glVertex2f (-0.5f, 0.0f);
        glVertex2f (0.0f, 0.5f);
        glVertex2f (0.5f, 0.0f);
        glEnd ();
        glfwSwapBuffers (main_window);

        /* Proccess all events, like close the window */
        glfwPollEvents ();
    }

    glfwDestroyWindow (main_window);
    /* Unload the library */
    glfwTerminate ();

    return 0;
}

