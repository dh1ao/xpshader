#ifndef XPUTIL_H
#define XPUTIL_H
#include <stdio.h>

char *xputil_ReadFile(char *file_name);
int xputil_FileExists(char *fname);
#else
extern char *xputil_ReadFile(char *file_name);
#endif