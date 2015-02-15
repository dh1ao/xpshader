#include "testbed.h"
#include "xpopengl.h"

#include "GL/freeglut.h"
#include "xputil.h"

/*  =======================================================================

    testbed_resizeWin

    Callback bei Fenstergrößenänderung

    ======================================================================= */
static void testbed_resizeWin( int w, int h )
{
  glViewport( 0, 0, w, h );
} // testbed_resizeWin


/*  =======================================================================

    testbed_Draw

    Callback zum Zeichnen

    ======================================================================= */
static void testbed_Draw( void )
{
    static short first_call = 1;

    glClear(GL_COLOR_BUFFER_BIT);

    if( first_call ) 
    {
        first_call = 0;

        if( TESTBED_PREPARE_CB != NULL )
            ( *TESTBED_PREPARE_CB )( );
        return;
    }

    if( TESTBED_DRAW_CB != NULL )
        ( *TESTBED_DRAW_CB )( );

     glutSwapBuffers();
     return;  
}

/*  =======================================================================

    main

    Initialisieren von GLUT etc.

    ======================================================================= */
int main( int argc, char **argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Peter's openGL Testbude");
    glutReshapeFunc(testbed_resizeWin);
    glutDisplayFunc(testbed_Draw);
    xpopengl_init( "build/vshader.glsl", "build/fshader.glsl" );
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   
    glutMainLoop();
    
    return 0;
} // main