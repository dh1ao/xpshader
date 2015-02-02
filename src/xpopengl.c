#include <stdlib.h>
#include "xpopengl.h"
#include "xputil.h"

/*
    Sammlung von OpenGL nahen Funktionen wie etwa initialisieren
*/


/*  =======================================================================

    xpopengl_printGLErrors

    Informationen über das Shaderprogramm ausgeben

    ======================================================================= */
void xpopengl_printProgInfo(GLuint prog)
{
    int maxLength;
    int length;
    glGetProgramiv(prog,GL_INFO_LOG_LENGTH,&maxLength);
    char log[maxLength];
    glGetProgramInfoLog(prog,maxLength,&length,log);
    printf("Shader Info %s\n", log );
} // xpopengl_printProgInfo

/*  =======================================================================

    xpopengl_printGLErrors

    OpenGL und Shader Fehlermeldungen ausgeben

    ======================================================================= */
void xpopengl_printGLErrors(void)
{
    GLenum err = glGetError();
    if (err == GL_NO_ERROR)
    {
        puts("glError NO ERROR");
        return;
    }

    while( err != GL_NO_ERROR) {
        switch( err ) {
            case GL_INVALID_ENUM : puts("glError INVALID ENUM"); break;
            case GL_INVALID_VALUE : puts("glError INVALID VALUE"); break;
            case GL_INVALID_OPERATION : puts("glError INVALID OPERATION"); break;
            case GL_OUT_OF_MEMORY : puts("glError OUT OF MEMORY"); break;
            default : puts("glError UNKNOWN ERROR"); break;
        }
        err = glGetError();
    }
} // xpopengl_printGLErrors

/*  =======================================================================

    xpopengl_init

    OpenGL und Shader initialisieren

    ======================================================================= */
void xpopengl_init(void)
{

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      /* Problem: glewInit failed, something is seriously wrong. */
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    /* Einlesen des Vertex- und Fragment Shader Programms */
    char *vshader_text = xputil_ReadFile( XPOPENGL_VSHADER_FILE );
    char *fshader_text = xputil_ReadFile( XPOPENGL_FSHADER_FILE );

    if (( ! vshader_text ) || ( ! fshader_text ))
    {
        puts("Can't find shader program");
        return;
    }

    /* Erzeugen, Zuordnen und Compilieren der Shader Programme */
    XPOpenGL_Vshader = glCreateShader(GL_VERTEX_SHADER);
    XPOpenGL_Fshader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource( XPOpenGL_Vshader,1,(const GLchar **)&vshader_text,NULL );
    glShaderSource( XPOpenGL_Fshader,1,(const GLchar **)&fshader_text,NULL );

    glCompileShader( XPOpenGL_Vshader );
    glCompileShader( XPOpenGL_Fshader );

    /* Klartext Shaderprogramme werden nicht mehr benötigt */
    free(vshader_text);  
    free(fshader_text);

    /* Shader Programm erzeugen, V und F Shader Linken und Programm aktiv machen */
    XPOpenGL_ShaderProgram = glCreateProgram();
    glAttachShader( XPOpenGL_ShaderProgram, XPOpenGL_Vshader );
    glAttachShader( XPOpenGL_ShaderProgram, XPOpenGL_Fshader );
    glLinkProgram( XPOpenGL_ShaderProgram );
    glUseProgram( XPOpenGL_ShaderProgram );

} // xpopengl_init 

/*  =======================================================================

    xpopengl_destroy

    Shader Programm entladen und Programm deaktivieren

    ======================================================================= */

void xpopengl_destroy(void)
{
    glUseProgram( 0 );
    glDeleteShader( XPOpenGL_Vshader );
    glDeleteShader( XPOpenGL_Fshader );
    glDeleteProgram( XPOpenGL_ShaderProgram );

} // xpopengl_destroy

/*  =======================================================================

    xpopengl_num_of_extensions

    liefert die Zahl der OpenGL Erweiterungen des Graka Herstellers

    ======================================================================= */
int xpopengl_num_of_extensions( void )
{
    GLint num_exts;
    glGetIntegerv( GL_NUM_EXTENSIONS, &num_exts );
    return ( int ) num_exts;
} // xpopengl_num_of_extensions

/*  =======================================================================

    xpopengl_print_extensions

    Gibt die Definitionsnamen aller implementierten Erweiterungen aus

    ======================================================================= */
void xpopengl_print_extensions( void )
{
    printf("%s\n", ( const char * )glGetString( GL_EXTENSIONS ) );
    
} // xpopengl_print_extensions

/*  =======================================================================

    xpopengl_getShaderProgram

    Die ID des Shader Programmes liefern (z.B. damit ausserhalb die Shader 
    Attribute gelesen werden können)

    ======================================================================= */
GLuint xpopengl_getShaderProgram(void)
{ 
    return XPOpenGL_ShaderProgram;
} // xpopengl_getShaderProgram