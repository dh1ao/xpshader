#ifndef XPDRAW_H
#define XPDRAW_H

#ifndef _XPLMDisplay_h_
#include "XPLMDisplay.h"
#endif

static xpdraw_VertexBuffer;
static void (*xpdraw_PrepareSceneCB)(void);

void xpdraw_init(void);
void xpdraw_registerCB(void);
int xpdraw_CB(  XPLMDrawingPhase inPhase,    
                int inIsBefore,    
                void *inRefcon );
void xpdraw_registerPrepareScene( void (*f)( void ));
#else

extern void xpdraw_init(void);
extern void xpdraw_registerPrepareScene( void (*f)( void ));
#endif