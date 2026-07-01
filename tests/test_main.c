#include "test_d_array.h"
#include "test_neuron.h"
#include "test_harness.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {

    char *green = "\x1b[32m";
    char *reset = "\x1b[0m";
    
    // Test list ...
    test my_tests[] = {
        // Dynamic array tests.
        {"d_array init", test_dArray_init},
        {"d_array push single", test_dArray_push_single},
        {"d_array push realloc", test_dArray_push_realloc},
        {"d_array get", test_dArray_get},
        // Neuron tests.
        {"neuron init", test_neuron_init},
        {"neuron stim pos", test_neuron_stimulate_pos},
        {"neuron stim neg", test_neuron_stimulate_neg},
        {"neuron fires", test_neuron_fires},
        {"neuron decay", test_neuron_decay_single},
        {"neuron decay many", test_neuron_decay_many},
        {"neuron decay nonzero", test_neuron_decay_nonzero},
        {"neuron not exceed bounds", test_neuron_not_exceed_bound}
    };

    // Get the size of the array..
    size_t test_count = sizeof(my_tests) / sizeof(my_tests[0]);

    // Loop the array.
    for (size_t i = 0; i < test_count; i++) {
        my_tests[i].fn();
        printf("%sPASS:%s %s\n", green, reset, my_tests[i].test_name);
    }

}
