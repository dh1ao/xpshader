#ifndef XPSCENE_H
#define XPSCENE_H

#ifndef XPOPENGL_H
#include "xpopengl.h"
#endif

#include <stdio.h>

static GLuint vbo = -1;
static GLuint vao = -1;

void xpscene_prepare_triangle( void );
void xpscene_draw_triangle( void );

#else

extern void xpscene_prepare_triangle( void );
extern void xpscene_draw_triangle( void );

#endif // XPSCENE_H

