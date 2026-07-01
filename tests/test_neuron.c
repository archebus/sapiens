#include "neuron.h"
#include <assert.h>

void test_neuron_init() {
    // Contract: can init a neuron with floats.
    neuron n = create_neuron(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    assert(n.activation == 0.0);
}

void test_neuron_stimulate_pos() { 
    neuron n = create_neuron(0.0, 0.0, 0.0, 0.0, 10.0, 0.0);
    stimulate(&n, 7.0);
    assert(n.activation == 7.0);
}

void test_neuron_stimulate_neg() {
    
}

void test_neuron_fires() {

}

void test_neuron_decay_single() {

}

void test_neuron_decay_many() {

}
