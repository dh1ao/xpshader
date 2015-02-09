#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "xppixel.h"
#include "xputil.h"

#define NumberOfPixels 5000000
GLfloat PixelPositions[NumberOfPixels][3];

/*  =======================================================================

    xppixel_prepareCB

    ein paar tausend Pixel in den VOB schicken


    ======================================================================= */
void xppixel_prepareCB( void )
{
    static GLint position_attribute;
    static GLint offset_attribute;
    static GLint farbe_attribute;

 
    GLfloat offset[3] = { 0.0, 0.0, 0.0};
   
    unsigned int i;
    
    srand( time( NULL ) );

    for( i=0; i<NumberOfPixels; i++ )
    {
        PixelPositions[i][0] = ( float )( rand( ) % 10000 );
        PixelPositions[i][1] = ( float )( rand( ) % 100 );
        PixelPositions[i][2] = ( float )( rand( ) % 60000 );
    }


    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers( 1, &vob );
    glBindBuffer(GL_ARRAY_BUFFER,vob);

    glBufferData( GL_ARRAY_BUFFER, 3*sizeof( GLfloat )*NumberOfPixels, NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, 3*sizeof( GLfloat )*NumberOfPixels, PixelPositions );
    glBufferSubData( GL_ARRAY_BUFFER, 3*sizeof( GLfloat )*NumberOfPixels, 3*sizeof( GLfloat ), offset );
//    glBufferSubData( GL_ARRAY_BUFFER, sizeof( dreieck ), sizeof( farbe ), farbe );

    position_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Position"
            );

    offset_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Offset"
            );
/*
    farbe_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Farbe"
            );
*/
    glVertexAttribPointer( position_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 0 ) );
    glVertexAttribPointer( offset_attribute, 1, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 3*sizeof( GLfloat )*NumberOfPixels ) );
    glEnableVertexAttribArray(position_attribute);
    glEnableVertexAttribArray(offset_attribute);

/*
    glVertexAttribPointer( farbe_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof( dreieck) ) );
    glEnableVertexAttribArray( farbe_attribute );
*/    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return;
} // xppixel_prepareCB


/*  =======================================================================

    xppixel_drawCB

    ein paar tausend Pixel an den XPlane Himmel malen


    ======================================================================= */
void xppixel_drawCB( void )
{

    XPLMSetGraphicsState(0, 0, 0, 0, 0, 0, 0);
    glDisable( GL_CULL_FACE );

    glUseProgram( xpopengl_getShaderProgram() );
    glBindVertexArray( vao );
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glDrawArrays( GL_POINTS, 0, NumberOfPixels );

    if( XPUTIL_REF_POINT_CHANGED )
        puts( "REF POINT CHANGED" );

    glUseProgram(0);
    glBindVertexArray(0);
} // xppixel_drawCB