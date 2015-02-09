
#include "xpdrawtexture.h"
#include "xputil.h"


void xpdrawtexture_prepare(void)
{
   static GLint position_attribute;
    static GLint farbe_attribute;
    static GLint origin_attribute;

    double x, y, z;
    XPLMWorldToLocal( 54.6, 8.8, 500.0, &x,&y,&z );

    float origin[3];
    origin[0] = x; 
    origin[1] = y; 
    origin[2] = z;

    float dreieck[4][3] =   {
                                { -50.5,  0,  50.0 },
                                {  50.5,  0,  50.0 },
                                {  50.5,   50.5,  50.0 },
                                { -50.5,   50.5,  50.0 }
                            };


    int indices[6] = {0,1,2,2,3,0};

    float farbe[3][4] = {
                            { 1.0, 0.0, 0.0, 1.0 },
                            { 0.0, 1.0, 0.0, 1.0 },
                            { 0.0, 0.0, 1.0, 1.0 }
                        };
		
/*
	XPLMWorldToLocal( 54.6, 8.8, 500.0, &x,&y,&z );
	dreieck[0][0] = x; dreieck[0][1] = y; dreieck[0][2] = z;

	XPLMWorldToLocal( 54.6, 8.9, 500.0, &x,&y,&z );
	dreieck[1][0] = x; dreieck[1][1] = y; dreieck[1][2] = z;

    	XPLMWorldToLocal( 54.8, 8.9, 500.0, &x,&y,&z );
    	dreieck[2][0] = x; dreieck[2][1] = y; dreieck[2][2] = z;

    	XPLMWorldToLocal( 54.8, 8.8, 500.0, &x,&y,&z );
    	dreieck[3][0] = x; dreieck[3][1] = y; dreieck[3][2] = z;
*/
/*
	XPLMWorldToLocal( 54.68428, 8.52825, 2050.0, &x,&y,&z );
	dreieck[0][0] = x; dreieck[0][1] = y; dreieck[0][2] = z;

	XPLMWorldToLocal( 54.68401, 8.53690, 2050.0, &x,&y,&z );
	dreieck[1][0] = x; dreieck[1][1] = y; dreieck[1][2] = z;;

    	XPLMWorldToLocal( 54.68431, 8.53711, 2050.0, &x,&y,&z );
    	dreieck[2][0] = x; dreieck[2][1] = y; dreieck[2][2] = z;

    	XPLMWorldToLocal( 54.68458, 8.52855, 2050.0, &x,&y,&z );
    	dreieck[3][0] = x; dreieck[3][1] = y; dreieck[3][2] = z;
*/

    int i,j;
    for ( i =0; i<4; i++){
		for ( j=0; j<3; j++){
			printf("%f ", dreieck[i][j]);
		}
		printf("\n");
    }
    printf("\n");



    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers( 1, &vbo );
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData( GL_ARRAY_BUFFER, sizeof( dreieck )+sizeof( farbe )+sizeof( origin ), NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof( dreieck ), dreieck );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof( dreieck ), sizeof( farbe ), farbe );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof( dreieck )+sizeof( farbe ), sizeof( origin ), origin );


    glGenBuffers( 1, &eab );
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eab);
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );


    position_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Position"
            );

    farbe_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Farbe"
            );

    origin_attribute = glGetAttribLocation(
            xpopengl_getShaderProgram(), 
            "in_Origin"
            );

    glVertexAttribPointer( position_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 0 ) );
    glEnableVertexAttribArray(position_attribute);

    glVertexAttribPointer( farbe_attribute, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof( dreieck) ) );
    glEnableVertexAttribArray( farbe_attribute );
    
    glVertexAttribPointer( origin_attribute, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof( dreieck) + sizeof( farbe) ) );
    glEnableVertexAttribArray( origin_attribute );

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return;
}

void xpdrawtexture_draw(void)
{
    XPLMSetGraphicsState(0, 0, 0, 0, 0, 0, 0);
    glDisable( GL_CULL_FACE );

    glUseProgram( xpopengl_getShaderProgram() );
    glBindVertexArray( vao );
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    if (XPUTIL_REF_POINT_CHANGED) {
	puts("REf point changed");
    }
    //glDrawArrays( GL_TRIANGLES, 0, 3 );
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glUseProgram(0);
    glBindVertexArray(0);
    
}
