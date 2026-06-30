#include "test_d_array.h"

int main(void) {
    test_dArray_init();
    test_dArray_push_single();
    test_dArray_push_realloc();
    test_dArray_get();
}
