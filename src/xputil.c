#include <unistd.h>
#include <stdlib.h>

#include "XPLMDataAccess.h"
#include "xputil.h"



static XPLMDataRef XPUTIL_LonDataRef;
static XPLMDataRef XPUTIL_LatDataRef;

static double XPUTIL_RefPositionLon;
static double XPUTIL_RefPositionLat;

/*  =======================================================================

    xputil_initRefPoint

    aktuellen Referenzpunkt der geladenen Szenerie merken

    ======================================================================= */
void xputil_initRefPoint( void )
{
    XPUTIL_LatDataRef = XPLMFindDataRef("sim/flightmodel/position/lat_ref");
    XPUTIL_LonDataRef = XPLMFindDataRef("sim/flightmodel/position/lon_ref");
    XPUTIL_RefPositionLon = XPLMGetDataf( XPUTIL_LonDataRef );
    XPUTIL_RefPositionLat = XPLMGetDataf( XPUTIL_LatDataRef );

} // xputil_initRefPoint

/*  =======================================================================

    xputil_ReadRefPoint

    aktuellen Referenzpunkt der geladenen Szenerie lesen und gemerkten 
    globalen Wert überschreiben
    ======================================================================= */
short xputil_ReadRefPoint( void )
{
    double x,y;
    x = XPLMGetDataf( XPUTIL_LonDataRef );
    y = XPLMGetDataf( XPUTIL_LatDataRef );

    if( ( x != XPUTIL_RefPositionLon ) || ( y != XPUTIL_RefPositionLat ) )
    {
        XPUTIL_RefPositionLon = x;
        XPUTIL_RefPositionLat = y;
        return 1;
    }
    else
        return 0;

} // xputil_ReadRefPoint


/*  =======================================================================

    xputil_ReadFile

    eine Textdatei in einen Buffer einlesen und diesen Buffer zurückgeben

    ======================================================================= */
char *xputil_ReadFile(char *file_name)
{

    if( !xputil_FileExists(file_name))
    {
        printf("File not found %s\n", file_name);
        return NULL;
    }

    FILE *f = fopen(file_name, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *string = (char*) malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
    return string;
} // xputil_ReadFile

/*  =======================================================================

    xputil_FileExists

    gibt 1 zurück, wenn Datei existiert, sonst 0

    ======================================================================= */

int xputil_FileExists(char *fname)
{
    if( access( fname, F_OK ) != -1 )
        return 1;
    else
        return 0;

} // xputil_FileExists