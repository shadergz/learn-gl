project ('learn-gl', ['cpp'],
    version: '0.0.4'

)

opengl_dep = dependency ('gl')
glfw3_dep = dependency ('glfw3')
glew_dep = dependency ('glew')

executable ('triangle', 
    sources: [
        'triangle.cc'
    ],
    dependencies: [opengl_dep, glfw3_dep]

)


executable ('color_01',
    sources: [
        'color_01.cc'
    ],
    dependencies: [opengl_dep, glfw3_dep]
)

executable ('buffer_01',
    sources: [
        'buffer_01.cc'
    ],
    dependencies: [opengl_dep, glfw3_dep, glew_dep]
)

executable ('shader_01',
    sources: [
        'shader_01.cc'
    ],
    dependencies: [opengl_dep, glfw3_dep, glew_dep]

)
