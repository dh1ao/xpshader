/*
	XPlane plugin "Hauptprogramm" Hier sind die von XPlane verlangten Minimalfunktionen
*/

#include <stdio.h>
#include <string.h>

#include "XPLMPlugin.h"

#include "xputil.h"
#include "xpdraw.h"

/*  =======================================================================

    XPluginStart

    wird von XPlane aufgerufen um das eigene Plugin zu initialisierem

	======================================================================= */

PLUGIN_API int XPluginStart(char * outName,
                            char * outSig,
                            char * outDesc)
{
    strcpy(outName, "XP10 Shadertest");
    strcpy(outSig, "XP10 Shadertest");
    strcpy(outDesc, "mein zweiter XP Shader");
    xpdraw_init();
    puts("I'M ALIVE !!!!!!!!!!!!!");

    return 1;
} /* XPluginStart */

/*  =======================================================================

    XPluginStop

    Aufräumarbeiten beim Beenden von XPlane hierhin

    ======================================================================= */

PLUGIN_API void XPluginStop(void)
{
    xpopengl_destroy();
    puts("Bye bye XPlane");
} /* XPluginStop */

/*  =======================================================================

    XPluginDisable

    wird vom XPlane Plugin Manager beim "disablen" von Plugins aufgerufen

    ======================================================================= */

PLUGIN_API void XPluginDisable(void)
{
    xpopengl_destroy();
} /* XPluginDisable */

/*  =======================================================================

    XPluginEnable

    wird vom XPlane Plugin Manager beim "enablen" von Plugins aufgerufen

    ======================================================================= */

PLUGIN_API int XPluginEnable( void ) 
{
    xpdraw_init();
    return 1;
} /* XPluginEnable */

/*  =======================================================================

    XPluginReceiveMessage

    Interplugin Gespraechskanal... Auch Meldungen uerber Absturz etc.

    ======================================================================= */

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho,
        long                                       inMessage,
        void *                                     inParam)
{
    return;
} /* XPluginReceiveMessage */