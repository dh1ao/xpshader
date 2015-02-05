#ifndef XPUTIL_H
#define XPUTIL_H
#include <stdio.h>

#define XPUTIL_REF_POINT_CHANGED ( xputil_ReadRefPoint( ) )

char *xputil_ReadFile(char *file_name);
int xputil_FileExists(char *fname);
void xputil_initRefPoint( void );
short xputil_ReadRefPoint( void );

#else
extern char *xputil_ReadFile(char *file_name);
extern void xputil_initRefPoint( void );
extern short xputil_ReadRefPoint( void );
#endif