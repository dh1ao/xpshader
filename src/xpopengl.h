#ifndef XPOPENGL_H
#define XPOPENGL_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define XPOPENGL_VSHADER_FILE "./Resources/plugins/vshader.glsl"
#define XPOPENGL_FSHADER_FILE "./Resources/plugins/fshader.glsl"

static GLuint XPOpenGL_Vshader, XPOpenGL_Fshader;
static GLuint XPOpenGL_ShaderProgram;

void xpopengl_printProgInfo(GLuint prog);
void xpopengl_printGLErrors(void);
void xpopengl_init( char *vshader_filename, char *fshader_filename );
void xpopengl_destroy(void);
int xpopengl_num_of_extensions(void);
void xpopengl_print_extensions(void);
GLuint xpopengl_getShaderProgram(void);
GLuint xpopengl_loadTexture(const char* filename);
void xpopengl_printOpenGLInfo( void );

#else

extern void xpopengl_printProgInfo(GLuint prog);
extern void xpopengl_printGLErrors(void);
extern void xpopengl_init( char *vshader_filename, char *fshader_filename );
extern void xpopengl_destroy(void);
extern int xpopengl_num_of_extensions(void);
extern void xpopengl_print_extensions(void);
extern GLuint xpopengl_getShaderProgram(void);
extern GLuint xpopengl_loadTexture(const char* filename);
extern void xpopengl_printOpenGLInfo( void );
#endif // XPOPENGL_H

#define BUFFER_OFFSET(i) ((void*)(i))
