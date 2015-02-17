add_library("xpShadertest" SHARED xps.c xputil.c xpdraw.c xpopengl.c xpscene.c xppixel.c lodepng.c tb_triangle.c)


ADD_CUSTOM_COMMAND(TARGET xpShadertest POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       $<TARGET_FILE:xpShadertest>
                       ${COPY_TO_PATH}/xpShadertest.xpl
                   COMMENT "Copying 'xpShadertest' library to '${COPY_TO_PATH}/xpShadertest.xpl'")

target_link_libraries(xpShadertest GL GLEW )

#add_definitions( -D_NO_XPLANE )
add_executable(testbed testbed.c xpopengl.c lodepng.c xputil.c tb_pixel.c tb_triangle.c)
target_compile_definitions(testbed PUBLIC "_NO_XPLANE=1")
target_link_libraries(testbed glut GL GLEW m )