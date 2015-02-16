
#include "xpdrawtexture.h"
#include "xputil.h"
#include "xpopengl.h"
#include <stdlib.h>
#include <math.h>

#define NumberOfObjects 100
GLuint loadTexture(const char *filename, unsigned id, unsigned size)
{
    GLuint textureID;
    unsigned error;
    unsigned char *image;
    unsigned width, height;

    error = lodepng_decode32_file(&image, &width, &height, filename);
    if (error)
    {
        printf("error %u: %s\n", error, lodepng_error_text(error));
    }
    else
    {
        /*use image here*/
        puts("image loading ok");
        printf("--width: %u\n", width);
        printf("--height: %u\n", height);

        // Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
        size_t u2 = 1;
        while (u2 <  size) u2 *= 2;
        size_t v2 = 1;
        while (v2 <  size) v2 *= 2;

        unsigned pix = id * size;
        unsigned row = trunc(pix / width) * size;
        unsigned col = pix % width;
        printf("--row: %u\n", row);
        printf("--col: %u\n", col);
        printf("--size: %u\n", size);

        unsigned char *image2 = malloc(u2 * v2 * 4);
        size_t y, x, c = 0;
        for (y = 0; y < size; y++)
            for (x = 0; x < size; x++)
                for (c = 0; c < 4; c++)
                {
                    image2[4 * u2 * y + 4 * x + c] = image[4 * width * (y + row) + 4 * (x + col) + c];
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
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        free(image);
        free(image2);
        return textureID;
    }
}

void xpdrawtexture_prepare(void)
{
    static GLint object_attribute;
    static GLint cloud_id_attribute;
    static GLint alpha_attribute;

    const char *filename = "./Resources/bitmaps/world/clouds/cloud_puff0.png";
    GLuint textureID;
    //textureID = loadTexture(filename, 6, 256);
    textureID = loadTexture(filename, 0, 1024);

    float alpha[4] = { 1.0, 1.0, 1.0, .5 };
    
    
    GLfloat ObjectPositions[NumberOfObjects][4];
    unsigned i = 0;
    unsigned cloud_lower_level = 5000;
    unsigned cloud_upper_level = 10000;

    for (i = 0; i < NumberOfObjects; i++)
    {
        ObjectPositions[i][0] = 55.031641; //(float) (rand() % 10000000 + 55031641)/1000000;
        ObjectPositions[i][1] = 8.445144; //(float) (rand() % 10000000 + 8445144)/1000000;
        ObjectPositions[i][2] = cloud_lower_level; //(float) (rand() % 1000 + 5000);
        printf("%f\n", ObjectPositions[i][0]);
        printf("%f\n", ObjectPositions[i][1]);
        printf("%f\n\n", ObjectPositions[i][2]);
        double x, y, z;
        XPLMWorldToLocal(ObjectPositions[i][0], ObjectPositions[i][1], ObjectPositions[i][2], &x, &y, &z);
        ObjectPositions[i][0] = x + (float) (rand() % 15000) - 7500;
        ObjectPositions[i][1] = y + (float) (rand() % (cloud_upper_level - cloud_lower_level))*2 + cloud_lower_level;
        ObjectPositions[i][2] = z + (float) (rand() % 15000) - 7500;
    } 

    int CloudId[2] = { rand() % 4, rand() % 4};

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(ObjectPositions) + sizeof(alpha) + sizeof(CloudId), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(ObjectPositions), ObjectPositions);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(ObjectPositions), sizeof(alpha), alpha);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(ObjectPositions) + sizeof(alpha), sizeof(CloudId), CloudId);

    xpopengl_printProgInfo(xpopengl_getShaderProgram());
    xpopengl_printGLErrors();

    object_attribute = glGetAttribLocation(xpopengl_getShaderProgram(), "in_Object");
    alpha_attribute = glGetAttribLocation(xpopengl_getShaderProgram(), "in_Alpha");
    cloud_id_attribute = glGetAttribLocation(xpopengl_getShaderProgram(), "in_CloudId");

    glVertexAttribPointer(object_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(object_attribute);
    glVertexAttribPointer(alpha_attribute, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(alpha_attribute);
    glVertexAttribPointer(cloud_id_attribute, 2, GL_SHORT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(cloud_id_attribute);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    int p = xpopengl_getShaderProgram();
    GLint texUnitLoc = glGetUniformLocation(p, "texUnit");
    glProgramUniform1i(p, texUnitLoc, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    return;
}

void xpdrawtexture_draw(void)
{
    XPLMSetGraphicsState(1, 1, 0, 1, 1, 1, 0);
    glDisable(GL_CULL_FACE);
    glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
    glPointParameteri(GL_POINT_SPRITE_COORD_ORIGIN, GL_UPPER_LEFT);
    glEnable(GL_POINT_SPRITE);
    glEnable(GL_PROGRAM_POINT_SIZE);

    glUseProgram(xpopengl_getShaderProgram());
    glBindVertexArray(vao);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    if (XPUTIL_REF_POINT_CHANGED)
    {
        puts("REf point changed");
    }
    glDrawArrays( GL_POINTS, 0, NumberOfObjects );
    glUseProgram(0);
    glBindVertexArray(0);

}
