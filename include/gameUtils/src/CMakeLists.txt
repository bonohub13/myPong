set(OpenGL_GL_PREFERENCE GLVND)

add_library(gameUtils
  SHARED
    windowProfile.cpp
    score.cpp
    utils.cpp
    racket.cpp
    ball.cpp
)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIR} )
target_link_libraries(gameUtils ${OPENGL_LIBRARIES} )

target_include_directories(gameUtils
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)