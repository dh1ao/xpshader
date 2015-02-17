/*
#include "xpscene.h" // hier die jeweils eigene Header Datei einbinden

#define XPDRAW_PREPARE_CB xpscene_prepare_triangle
#define XPDRAW_DRAW_CB xpscene_draw_triangle
*/

/*
#include "xppixel.h" // hier die jeweils eigene Header Datei einbinden

#define XPDRAW_PREPARE_CB xppixel_prepareCB
#define XPDRAW_DRAW_CB xppixel_drawCB
*/

extern void tb_tri_prepapre( void );
extern void tb_tri_draw( void );

#define XPDRAW_PREPARE_CB tb_tri_prepapre
#define XPDRAW_DRAW_CB tb_tri_draw