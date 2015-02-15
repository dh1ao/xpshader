#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "XPLMDataAccess.h"
#include "xputil.h"



static XPLMDataRef XPUTIL_LonDataRef;
static XPLMDataRef XPUTIL_LatDataRef;

static double XPUTIL_RefPositionLon;
static double XPUTIL_RefPositionLat;


#ifndef _NO_XPLANE
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
#endif // _NO_XPLANE

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

/*  =======================================================================

    xputil_ReadObjectFile

    liest eine (Blender obj) Datei ein und legt die benötigten Puffer an

    ======================================================================= */

void xputil_ReadObjectFile( char *filename, double **vertex_buffer, int *vcount )
{
    if( ! xputil_FileExists( filename ) )
    {
        printf("Object File %s nicht gefunden\n", filename );
        return;
    }

    FILE *f = fopen(filename, "rb");
    char c='z';
    float x,y,z;
    double *buffer;
    int count = 0;

    buffer = ( double * )calloc( 1000, 3*sizeof( double ) );
    while( ! feof( f ) ) 
    {
        fscanf( f, "%c %f %f %f\n", &c, &x, &y, &z);
        if( c == 'f' )       
            continue;
            //printf("f %d %d %d\n", ( int )x, ( int )y, ( int )z);
        if( c == 'v' )       
        {   
            if( count % 1000 == 0 )
                buffer = ( double * ) realloc( buffer, 1000*3*sizeof( double ) );

            *( buffer + count ) = x;
            *( buffer + count + 1 ) = y;
            *( buffer + count + 2 ) = z;
            count++;
            //printf("v %f %f %f\n", x, y, z);
        }
        else
            continue;
    }

    *vertex_buffer = ( double * ) realloc( buffer, count*3*sizeof( double ) );
    *vcount = count;
    
    fclose( f );
    
    return;

} // xputil_ReadObjectFile