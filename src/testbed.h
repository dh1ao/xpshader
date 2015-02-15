#ifndef TESTBED_H
#define TESTBED_H

extern void testbedtriangle_prepare( void );
extern void testbedtriangle_draw( void );

#define TESTBED_PREPARE_CB testbedtriangle_prepare 
#define TESTBED_DRAW_CB testbedtriangle_draw

#endif // TESTBED_H
