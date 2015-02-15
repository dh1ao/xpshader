#ifndef TESTBED_H
#define TESTBED_H

extern void testbedtriangle_prepare( void );
extern void testbedtriangle_draw( void );
extern void tb_tri_prepapre( void );
extern void tb_tri_draw( void );

#define TESTBED_PREPARE_CB tb_tri_prepapre
#define TESTBED_DRAW_CB tb_tri_draw

#endif // TESTBED_H
