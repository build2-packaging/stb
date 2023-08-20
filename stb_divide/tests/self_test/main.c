// We need to include this header for 'abs' function.
// Upstream self tests did not do that.
//
#include <stdlib.h>

#define STB_DIVIDE_IMPLEMENTATION
#define STB_DIVIDE_TEST
#include <stb_divide.h>
