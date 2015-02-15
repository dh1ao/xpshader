cmake_minimum_required(VERSION 2.8)

project("XP Shader Tests")

subdirs( src )

set(
    CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/build
    )

set(
    EXECUTABLE_OUTPUT_PATH 
    ${CMAKE_HOME_DIRECTORY}/build )

set(XP_SDK_INCLUDE_DIR
    /home/peter/Programming/xplane/sdk/CHeaders/XPLM/
    )

SET(COPY_TO_PATH /home/peter/xp10/Resources/plugins)
include_directories(${XP_SDK_INCLUDE_DIR} )

add_definitions(-DLIN=1)

