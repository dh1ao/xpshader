add_library("xpShadertest" SHARED xps.c xputil.c xpdraw.c xpopengl.c  xpdrawtexture.c lodepng.c)

ADD_CUSTOM_COMMAND(TARGET xpShadertest POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       $<TARGET_FILE:xpShadertest>
                       ${COPY_TO_PATH}/xpShadertest.xpl
                   COMMENT "Copying 'xpShadertest' library to '${COPY_TO_PATH}/xpShadertest.xpl'")

target_link_libraries(xpShadertest GL GLEW)
