
#include "xpscene.h"

static GLuint vao;

/*  =======================================================================

    xpscene_prepare_triangle

    wird einmalig in der DrawCB aufgerufen

    ======================================================================= */

void xpscene_prepare_triangle( void )
{

    static GLint position_attribute;
    static GLint farbe_attribute;
    double x, y, z;
    float dreieck[3][3] =   {
                                {  0.0, 100000.0, -10000.0   },
                                {  100000.0, -100000.0, -10000.0  },
                                {  -100000.0,-100000.0, -10000.0  }
                            };

    float farbe[3][4] = {
                            { 1.0, 0.0, 0.0, 1.0 },
                            { 0.0, 1.0, 0.0, 1.0 },
                            { 0.0, 0.0, 1.0, 1.0 }
                        };

    XPLMWorldToLocal( 54.385156, 7.901917, 500.0, &x,&y,&z );
    dreieck[0][0] = x; dreieck[0][1] = y; dreieck[0][2] = z;

    XPLMWorldToLocal( 54.618009, 9.945374, 510.0, &x,&y,&z );
    dreieck[1][0] = x; dreieck[1][1] = y; dreieck[1][2] = z;

    XPLMWorldToLocal( 55.486441, 8.561096, 520.0, &x,&y,&z );
    dreieck[2][0] = x; dreieck[2][1] = y; dreieck[2][2] = z;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers( 1, &vbo );
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData( GL_ARRAY_BUFFER, sizeof( dreieck )+sizeof( farbe ), NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof( dreieck ), dreieck );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof( dreieck ), sizeof( farbe ), farbe );

    position_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Position"
            );

    farbe_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Farbe"
            );

    glVertexAttribPointer( position_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 0 ) );
    glEnableVertexAttribArray(position_attribute);

    glVertexAttribPointer( farbe_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof( dreieck) ) );
    glEnableVertexAttribArray( farbe_attribute );
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return;
} // xpscene_prepare_triangle

/*  =======================================================================

    xpscene_draw_triangle

    sollte in der Draw Callback aufgerufen werden

    ======================================================================= */

void xpscene_draw_triangle( void )
{
    XPLMSetGraphicsState(0, 0, 0, 0, 0, 0, 0);
    glDisable( GL_CULL_FACE );

    glUseProgram( xpopengl_getShaderProgram() );
    glBindVertexArray( vao );
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glDrawArrays( GL_TRIANGLES, 0, 3 );

    glUseProgram(0);
    glBindVertexArray(0);
    
    return;
} // xpscene_draw_triangle