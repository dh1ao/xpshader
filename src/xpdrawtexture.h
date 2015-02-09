


#ifndef XPDRAWTEXTURE_H
#define XPDRAWTEXTURE_H

#ifndef XPOPENGL_H
#include "xpopengl.h"
#endif

#include <stdio.h>
#include "lodepng.h"

static GLuint vbo = -1;
static GLuint vao = -1;
static GLuint eab = -1;

void xpdrawtexture_prepare(void);
void xpdrawtexture_draw(void);
GLuint loadTexture(const char* filename);

#else

extern void xpdrawtexture_prepare(void);
extern void xpdrawtexture_draw(void);

#endif // XPDRAWTEXTURE_H
