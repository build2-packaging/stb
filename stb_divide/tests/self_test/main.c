// We need to include this header for 'abs' function.
// Upstream self tests did not do that.
//
#include <stdlib.h>

#define STB_DIVIDE_IMPLEMENTATION
#define STB_DIVIDE_TEST
// Avoid overflow in the self-test's own q*b+r verification when b is
// INT_MIN, which upstream's own header comment warns produces false
// negatives without this defined.
#define STB_DIVIDE_TEST_64 long long
#include <stb_divide.h>
