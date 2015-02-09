#ifndef XPPIXEL_H
#define XPPIXEL_H

#include "xpopengl.h"

static GLuint vao = -1;
static GLuint vob = -1;

void xppixel_prepareCB( void );
void xppixel_drawCB( void );

#else

extern void xppixel_prepareCB( void );
extern void xppixel_drawCB( void );

#endif // XPPIXEL_H
