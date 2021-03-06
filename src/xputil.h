#ifndef XPUTIL_H
#define XPUTIL_H
#include <stdio.h>

#define XPUTIL_REF_POINT_CHANGED ( xputil_ReadRefPoint( ) )

char *xputil_ReadFile(char *file_name);
int xputil_FileExists(char *fname);

#ifndef _NO_XPLANE
void xputil_initRefPoint( void );
short xputil_ReadRefPoint( void );
#endif

void xputil_ReadObjectFile( char *filename, double **vertex_buffer, int *vcount );

#else
extern char *xputil_ReadFile(char *file_name);
extern int xputil_FileExists(char *fname);

#ifndef _NO_XPLANE
extern void xputil_initRefPoint( void );
extern short xputil_ReadRefPoint( void );
#endif

extern void xputil_ReadObjectFile( char *filename, double **vertex_buffer, int *vcount );
#endif