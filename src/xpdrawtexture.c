
#include "xpdrawtexture.h"
#include "xputil.h"
#include "xpopengl.h"
#include <stdlib.h>

GLuint loadTexture(const char* filename) {
    GLuint textureID;
    unsigned error;
    unsigned char* image;
    unsigned width, height;

    error = lodepng_decode32_file(&image, &width, &height, filename);
    if (error) {
        printf("error %u: %s\n", error, lodepng_error_text(error));
    } else {
        /*use image here*/
        puts("image loading ok");
        printf("--width: %u\n", width);
        printf("--height: %u\n", height);


        // Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
        size_t u2 = 1;
        while (u2 < width) u2 *= 2;
        size_t v2 = 1;
        while (v2 < height) v2 *= 2;

        unsigned char* image2 = malloc(u2 * v2 * 4);
        size_t y, x, c = 0;
        for (y = 0; y < height; y++)
            for (x = 0; x < width; x++)
                for (c = 0; c < 4; c++) {
                    image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
                }

        puts("power of two version of the image created");
        printf("--width: %f\n", (double) u2);
        printf("--height: %f\n", (double) v2);

        // access to data: &image2[0];
        glEnable(GL_TEXTURE_2D);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //glPixelStorei(GL_UNPACK_ALIGNMENT,1);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
        glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BRGA, GL_UNSIGNED_BYTE, &image[0]);
        //glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
 
        //free(image);
        return textureID;
    }
}

void xpdrawtexture_prepare(void) {
    static GLint position_attribute;
    static GLint origin_attribute;
    static GLint alpha_attribute;


    const char* filename = "./Resources/bitmaps/world/clouds/cloud_puff0.png";
    GLuint textureID;
    textureID = loadTexture(filename);

    double x, y, z;
    XPLMWorldToLocal(54.631641, 8.545144, 1000.0, &x, &y, &z);
    float origin[3];
    origin[0] = x; 
    origin[1] = y; 
    origin[2] = z;

    float dreieck[4][3] = {
        { 0.0, 0.0, z},
        { 1.0, 0.0, z},
        { 1.0, 1.0, z},
        { 0.0, 1.0, z}
    };

    float alpha[4] = { 1,1,1,1 };


    int indices[6] = {0, 1, 2, 2, 3, 0};

    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%f ", dreieck[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof ( dreieck) + sizeof (origin) , NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof ( dreieck), dreieck);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof ( dreieck), sizeof ( origin), origin);
    //glBufferSubData(GL_ARRAY_BUFFER, sizeof ( dreieck)+ sizeof ( origin), sizeof ( alpha), alpha);

    glGenBuffers(1, &eab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof ( indices), indices, GL_STATIC_DRAW);

    xpopengl_printProgInfo(xpopengl_getShaderProgram());
    xpopengl_printGLErrors();

    position_attribute = glGetAttribLocation(xpopengl_getShaderProgram(),"in_Position");
    origin_attribute = glGetAttribLocation(xpopengl_getShaderProgram(),"in_Origin");
    //alpha_attribute = glGetAttribLocation(xpopengl_getShaderProgram(),"in_Alpha");

    glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(position_attribute);
    glVertexAttribPointer(origin_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof( dreieck)));
    glEnableVertexAttribArray(origin_attribute);
    //glVertexAttribPointer(alpha_attribute, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    //glEnableVertexAttribArray(alpha_attribute);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    int p = xpopengl_getShaderProgram();
    GLint texUnitLoc = glGetUniformLocation(p, "texUnit");
    glProgramUniform1i(p, texUnitLoc, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    return;
}

void xpdrawtexture_draw(void) {
    XPLMSetGraphicsState(1, 1, 0, 1, 1, 1, 0);
    glDisable(GL_CULL_FACE);
    glUseProgram(xpopengl_getShaderProgram());
    glBindVertexArray(vao);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    if (XPUTIL_REF_POINT_CHANGED) {
        puts("REf point changed");
    }
    //glDrawArrays( GL_TRIANGLES, 0, 3 );
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glUseProgram(0);
    glBindVertexArray(0);

}
