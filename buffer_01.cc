/*
 *  Source code written by Gabriel Correia
*/

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

constexpr GLint WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;

int main (int argc, char **argv)
{
    GLFWwindow *main_window;
    GLuint triangle_id;

    GLfloat triangle[6] = {
        -0.5f, 0.0f,
        -0.0f, 0.5f,
         0.5f, 0.0f
    };

    /*  Initializing the support library to give us multi-plataform
     *  features like a window and input events handler 
    */
    glfwInit ();

    /* Creating a window to render into it */
    main_window = glfwCreateWindow (WINDOW_WIDTH, WINDOW_HEIGHT, 
        "Buffer 01", nullptr, nullptr);
    glfwMakeContextCurrent (main_window);

    glewInit ();

    glGenBuffers (1, &triangle_id);
    glBindBuffer (GL_ARRAY_BUFFER, triangle_id);
    glBufferData (GL_ARRAY_BUFFER, 6 * sizeof (GLfloat), triangle, GL_STATIC_DRAW);

    glEnableVertexAttribArray (0);
    glVertexAttribPointer (0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof (GLfloat), 0);

    while (! glfwWindowShouldClose (main_window)) {
        /* Time to render something */
        glClear (GL_COLOR_BUFFER_BIT);
        glDrawArrays (GL_TRIANGLES, 0, 3);
        /*
        glBegin (GL_TRIANGLES);

        glVertex2f (-0.5f, 0.0f);
        glVertex2f (0.0f, 0.5f);
        glVertex2f (0.5f, 0.0f);
        glEnd ();
        */
        glfwSwapBuffers (main_window);
        /* Proccess all events, like close the window */
        glfwPollEvents ();
    }

    /* Destroy the created window */
    glfwDestroyWindow (main_window);

    /* Unload the library */
    glfwTerminate ();

    return 0;
}

