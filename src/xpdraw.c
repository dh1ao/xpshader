#include <stdio.h>
#include "xpdraw.h"
#include "xpopengl.h"
#include "xputil.h"
#include "xpinterface.h"    // hier hinein die Funktionsnamen für Prepare/Draw
/*
    Alles, was zum Zeichnen in XPlane gehört soll hierhin
    inkl. OpenGL Funktionen
*/


/*  =======================================================================

    xpdraw_init

    Alles was zum Zeichnen in XP gehört initialisieren

    ======================================================================= */
void xpdraw_init( void )
{
    xpdraw_registerCB( );
    xpopengl_init( NULL, NULL );

    /* die beiden Funktionen müssen dem Anwendungsfall nach registriert werden */
    xpdraw_registerPrepareScene( XPDRAW_PREPARE_CB );
    xpdraw_registerDrawScene( XPDRAW_DRAW_CB );

} // xpdraw_registerCB

/*  =======================================================================

    xpdraw_registerCB

    Zeichen Callback bei XPlane anmelden

    ======================================================================= */
void xpdraw_registerCB( void )
{

    XPLMRegisterDrawCallback( xpdraw_CB, 
                              xplm_Phase_Objects,
                              0,
                              NULL );
} /* xpdraw_registerCB */

/*  =======================================================================

    xpdraw_CB

    wird von XPlane aufgerufen wenn XPlane Objekte gezeichnet hat

    ======================================================================= */
int xpdraw_CB(  XPLMDrawingPhase inPhase,    
                int inIsBefore,    
                void *inRefcon )
{
    
    static short first_call = 1;

    if( first_call ) 
    {
        first_call = 0;

        xputil_initRefPoint( );
        if( xpdraw_PrepareSceneCB != NULL )
            ( *xpdraw_PrepareSceneCB )( );
        return 1;
    }

    if( xpdraw_DrawSceneCB != NULL )
        ( *xpdraw_DrawSceneCB )( );

    return 1;
} /* xpdraw_CB */

/*  =======================================================================

    xpdraw_registerPrepareScene

    sobald möglich die OpenGL Befehle in einer Funktion f ausführen, die
    OpenGL Objekte etc. anlegt. Diese Funktion wir nur einmal bei ersten Aufruf
    der Draw Callback verwendet


    ======================================================================= */
void xpdraw_registerPrepareScene( void (*f)( void ))
{
    xpdraw_PrepareSceneCB = f;
} // xpdraw_registerPrepareScene


/*  =======================================================================

    xpdraw_registerDrawScene

    sobald möglich die OpenGL Befehle in einer Funktion f ausführen, die
    OpenGL Objekte etc. anlegt. Diese Funktion wir nur einmal bei ersten Aufruf
    der Draw Callback verwendet


    ======================================================================= */
void xpdraw_registerDrawScene( void (*f)( void ))
{
    xpdraw_DrawSceneCB = f;
} // xpdraw_registerDrawScen
