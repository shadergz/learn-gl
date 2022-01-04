/*
 *  Source code written by Gabriel Correia
*/


#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

constexpr GLint WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;

static const std::string vertex =
    "#version 430 core\n"
    "layout (location = 0) in vec4 position;\n"
    "void main ()\n"
    "{\n"
    "   gl_Position = position;\n"
    "}\n";

static const std::string fragment =
    "#version 430 core\n"
    "layout (location = 0) out vec4 color;\n"
    "void main ()\n"
    "{\n"
    "   color = vec4 (0.0, 1.0, 0.0, 1.0);"
    "}\n";

GLuint CompileShader (const char *shader, GLenum type)
{
    GLuint shader_id;
    GLint status_id, status_lenght;
    char *status_str;
    
    shader_id = glCreateShader (type);

    glShaderSource (shader_id, 1, &shader, nullptr);
    glCompileShader (shader_id);
    glGetShaderiv (shader_id, GL_COMPILE_STATUS, &status_id);

    if (status_id != GL_TRUE) {
        glGetShaderiv (shader_id, GL_INFO_LOG_LENGTH, &status_lenght);
        status_str = static_cast<char*> (alloca (sizeof (char) * status_lenght));

        glGetShaderInfoLog (shader_id, status_lenght, &status_lenght, status_str);
        std::printf ("%s", status_str);
        glDeleteShader (shader_id);

        return 0;
    }

    return shader_id;
}

GLuint CompileProgram (const std::string &vertex, 
    const std::string &fragment)
{
    GLuint program, vertex_id, fragment_id;
    const char *vertex_str, *fragment_str;
    
    vertex_str = vertex.c_str ();
    fragment_str = fragment.c_str ();

    program = glCreateProgram ();

    if (!(vertex_id = CompileShader (vertex_str, GL_VERTEX_SHADER))) {
        glDeleteProgram (program);
        return 0;
    }

    if (!(fragment_id = CompileShader (fragment_str, GL_FRAGMENT_SHADER))) {
        glDeleteShader (vertex_id);
        glDeleteProgram (program);
        return 0;
    }

    glAttachShader (program, vertex_id);
    glAttachShader (program, fragment_id);
    glLinkProgram (program);
    glValidateProgram (program);

    glDeleteShader (vertex_id);
    glDeleteShader (fragment_id);
    return program;
}

void DeleteProgram (GLuint program)
{
    /*  Free the memory and marks the program to deletion,
     *  any shaders associeted with this program will be deleted too
     *  because of the subsequential call to glDeleteShader (this function)
     *  marks the last created shaders to deletion (when the program be freed).
    */
    glDeleteProgram (program);
}

int main (int argc, char **argv)
{
    GLint shader_program;
    GLuint triangle_id;
    GLFWwindow *main_window;

    GLfloat triangle[6] = {
        -0.5f, 0.0f,
        -0.0f, 0.5f,
         0.5f, 0.0f
    };

    glfwInit ();

    main_window = glfwCreateWindow (WINDOW_WIDTH, WINDOW_HEIGHT, 
        "Shader Test 01", nullptr, nullptr);
    
    glfwMakeContextCurrent (main_window);
    glewInit ();

    glGenBuffers (1, &triangle_id);
    glBindBuffer (GL_ARRAY_BUFFER, triangle_id);
    glBufferData (GL_ARRAY_BUFFER, 6 * sizeof (GLfloat), triangle, GL_STATIC_DRAW);

    glEnableVertexAttribArray (0);
    glVertexAttribPointer (0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof (GLfloat), 0);

    shader_program = CompileProgram (vertex, fragment);
    if (!shader_program)
        goto quit;

    glUseProgram (shader_program);

    while (! glfwWindowShouldClose (main_window)) {

        glDrawArrays (GL_TRIANGLES, 0, 3);
        glfwSwapBuffers (main_window);
        glfwPollEvents ();
    }

    DeleteProgram (shader_program);
quit:
    glfwDestroyWindow (main_window);
    glfwTerminate ();

    return 0;
}

