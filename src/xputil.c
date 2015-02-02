#include <unistd.h>
#include <stdlib.h>
#include "xputil.h"

/*
    Hilfsfunktionen, wie etwa Datei lesen etc.
*/

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