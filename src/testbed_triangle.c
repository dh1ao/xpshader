#include "xpopengl.h"
#include <stdlib.h>

#define NumberOfPixels 500

static GLuint vao = -1;
static GLuint vob = -1;
GLfloat PixelPositions[NumberOfPixels][3];

void testbedtriangle_prepare( void )
{
static GLint position_attribute;
    static GLint offset_attribute;
    static GLint farbe_attribute;

 
    GLfloat offset[3] = { 0.0, 0.0, 0.0};
   
    unsigned int i;
    
    srand( time( NULL ) );

    for( i=0; i<NumberOfPixels; i++ )
    {
        PixelPositions[i][0] = ( float )( ( double )rand( ) / ( double )RAND_MAX  );
        PixelPositions[i][1] = ( float )( ( double )rand( ) / ( double )RAND_MAX  );
        PixelPositions[i][2] = ( float )( ( double )rand( ) / ( double )RAND_MAX  );
    }


    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers( 1, &vob );
    glBindBuffer(GL_ARRAY_BUFFER,vob);

    glBufferData( GL_ARRAY_BUFFER, 3*sizeof( GLfloat )*NumberOfPixels, NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, 3*sizeof( GLfloat )*NumberOfPixels, PixelPositions );
    glBufferSubData( GL_ARRAY_BUFFER, 3*sizeof( GLfloat )*NumberOfPixels, 3*sizeof( GLfloat ), offset );

    position_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Position"
            );

    offset_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Offset"
            );

    glVertexAttribPointer( position_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 0 ) );
    glVertexAttribPointer( offset_attribute, 1, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 3*sizeof( GLfloat )*NumberOfPixels ) );
    glEnableVertexAttribArray(position_attribute);
    glEnableVertexAttribArray(offset_attribute);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return;
}

void testbedtriangle_draw( void )
{
    glDisable( GL_CULL_FACE );

    glUseProgram( xpopengl_getShaderProgram() );
    glBindVertexArray( vao );
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glDrawArrays( GL_POINTS, 0, NumberOfPixels );


    glUseProgram(0);
    glBindVertexArray(0);
}