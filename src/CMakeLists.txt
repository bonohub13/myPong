set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} )

add_executable(pong main.cpp)

target_link_libraries(pong ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} gameUtils)