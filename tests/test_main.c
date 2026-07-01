#include "test_d_array.h"
#include "test_neuron.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *test_name;
    void (*fn)(void);
} test;

int main(void) {

    char *green = "\x1b[32m";
    char *reset = "\x1b[0m";
    
    // Test list ...
    test my_tests[] = {
        {"d_array init", test_dArray_init},
        {"d_array push single", test_dArray_push_single},
        {"d_array push realloc", test_dArray_push_realloc},
        {"d_array get", test_dArray_get},
        {"neuron init", test_neuron_init},
        {"neuron stim", test_neuron_stimulate_pos} 
    };

    // Get the size of the array..
    size_t test_count = sizeof(my_tests) / sizeof(my_tests[0]);

    // Loop the array.
    for (size_t i = 0; i < test_count; i++) {
        my_tests[i].fn();
        printf("%sPASS:%s %s\n", green, reset, my_tests[i].test_name);
    }

}
