// The implementation uses 'memcpy' which,
// unfortunately, is not declared explicitly before.
// We add this header to remove warnings and compile
// errors on implicit function declarations.
//
#include <string.h>

#define STB_DXT_IMPLEMENTATION
#include <stb_dxt.h>

int main() {}
