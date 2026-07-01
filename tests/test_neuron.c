#include "neuron.h"
#include "test_harness.h"
#include <assert.h>
#include <stdlib.h>

// activation: the level of stimulation in this neuron.
float na = 0.0f;
// decay_rate: how quickly the neuron returns to resting.
float nd = 0.5f;
// resting_value: where this neuron naturally sits.
float nr = 0.0f;
// fire_threshold: controls when the neuron will fire.
float nf = 7.0f;
// upper_bound: the max value this neuron can reach.
float nu = 10.0f;
// lower_bound: the min value this neuron can reach.
float nl = 0.0f;

void test_neuron_init() {
    // Contract: can init a neuron with floats.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    assert(float_eq(n.activation, 0.0f));
}

void test_neuron_stimulate_pos() { 
    // Contract: neurons can be positively stimulated.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    stimulate(&n, 7.0f);
    assert(float_eq(n.activation, 7.0f));
}

void test_neuron_stimulate_neg() {
    // Contract: neurons can be negatively stimulated.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    stimulate(&n, 5.0f);
    stimulate(&n, -3.0);
    assert(float_eq(n.activation, 2.0f));
}

void test_neuron_fires() {
    // Contract: neurons over threshold will fire.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    stimulate(&n, 10.0f);
    assert(fired(&n) == 1);
    stimulate(&n, -5.0f);
    assert(fired(&n) == 0);
    stimulate(&n, 2.0f);
    assert(fired(&n) == 1);
}

void test_neuron_decay_single() {
    // Single decay hits correct value.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    stimulate(&n, 10.0f);
    decay(&n);
    // Decay of 0.5 should have moved half way to 0.0 (-5.0)
    assert(float_eq(n.activation, 5.0f));
}

void test_neuron_decay_many() {
    // Multiple decays hit correct value.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    stimulate(&n, 10.0f);
    for (size_t i = 0; i < 3; i++) {
        decay(&n);
    }
    // 3 decay points to 0 = 1.25
    assert(float_eq(n.activation, 1.25f));
}

void test_neuron_decay_nonzero() {
    // Decays target the non zero resting point
    neuron n = create_neuron(na, nd, 5.0f, nf, nu, nl);
    stimulate(&n, 10.0f);
    decay(&n);
    // 0.5 decay from 10 to 5 should be 7.5
    assert(float_eq(n.activation, 7.5f));
}

void test_neuron_not_exceed_bound() {
    // Neurons should never exceed their bounds.
    neuron n = create_neuron(na, nd, nr, nf, nu, nl);
    stimulate(&n, 20.0f);
    assert(float_eq(n.activation, 10.0f));
    stimulate(&n, -20.0f);
    assert(float_eq(n.activation, 0.0f));
}
