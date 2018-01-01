set(GLFW_INCLUDE_PATH "" CACHE PATH "The directoruy that contains GLFW/glfw.h")
set(GLFW_LIBRARY "" CACHE FILEPATH "libglfw.a or glfw.lib")

set(GLM_INCLUDE_PATH "" CACHE PATH "")

include_directories(
    ${GLFW_INCLUDE_PATH}
    ${GLM_INCLUDE_PATH}
)

set(EXAMPLE1_SOURCE_FILES example1.cc)

add_executable(example1
    ${EXAMPLE1_SOURCE_FILES}
)
target_link_libraries(example1
    ${OPENGL_LIBRARY}
    ${GLFW_LIBRARY}
)