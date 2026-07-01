#ifndef TEST_HARNESS
#define TEST_HARNESS
#include <math.h>

// Tolerance for fpi
// idiomatic for testing floats.
#define EPSILON 0.0001f
#define float_eq(a, b) (fabsf((a) - (b)) < EPSILON)

typedef struct {
    char *test_name;
    void (*fn)(void);
} test;

#endif
