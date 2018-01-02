include_directories(
    ${LPGL_INCLUDE}
)

set(LPGL_SOURCE_FILES lpgl.cc)

add_library(lpgl
    ${LPGL_SOURCE_FILES}
)