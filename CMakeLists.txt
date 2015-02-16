cmake_minimum_required(VERSION 2.8)

project("XP Shader Tests")

subdirs(src)

set(
    CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/build
    )

set(XP_SDK_INCLUDE_DIR
    /home/markus/Programming/XPLM
    )


SET(COPY_TO_PATH /media/markus/XPlane_SSD/X-Plane\ 10\ dev/Resources/plugins)
include_directories(${XP_SDK_INCLUDE_DIR} /usr/include)

add_definitions(-DLIN=1)

file(GLOB MY_PUBLIC_SHADERS
  "build/*.glsl"
)
file(COPY ${MY_PUBLIC_SHADERS} DESTINATION ${COPY_TO_PATH})
