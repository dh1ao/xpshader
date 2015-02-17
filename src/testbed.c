#include "testbed.h"
#include "xpopengl.h"

#include "GL/freeglut.h"
#include "xputil.h"

void testbed_calculateFPS( void );

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
} // testbed_Draw

/*  =======================================================================

    testbed_Keyboard

    Bei ESC Programm beenden

    ======================================================================= */
void testbed_Keyboard( unsigned char key, int x, int y)
{
    switch ( key  ) {
    case 27 :
                glutDestroyWindow ( 0 );
                exit (0);
                break;
    case GLUT_KEY_RIGHT : break;
    }

} // testbed_Keyboard

/*  =======================================================================

    testbed_calculateFPS

    Frames per second ausgeben (typisch in Idle Callback)

    ======================================================================= */
void testbed_calculateFPS( void )
{
    static int frameCount = 0;
    static float fps = 0.0;
    static int previousTime = 0;

    //  Increase frame count
    frameCount++;

    //  Get the number of milliseconds since glutInit called
    //  (or first call to glutGet(GLUT ELAPSED TIME)).
    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    //  Calculate time passed
    int timeInterval = currentTime - previousTime;

    if(timeInterval > 1000)
    {
        //  calculate the number of frames per second
        fps = frameCount / (timeInterval / 1000.0f);

        //  Set time
        previousTime = currentTime;

        //  Reset frame count
        frameCount = 0;
    }
    printf("%f\n", fps);
} // testbed_calculateFPS

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
    //glutIdleFunc( testbed_calculateFPS );
    glutIdleFunc( tb_tri_idle );
    glutKeyboardFunc( testbed_Keyboard );
    xpopengl_init( "./vshader.glsl", "./fshader.glsl" );
    xpopengl_printOpenGLInfo( );
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   
    glutMainLoop();
    
    return 0;
} // main