#include "neuron.h"
#include <stdbool.h>

// Pushes a neuron in a certain direction.
// Mutates the activation field.
void stimulate(neuron *n, float push) {
    float new_value = n->activation + push;
    if (new_value > n->upper_bound)
        n->activation = n->upper_bound;
    else if (new_value < n->lower_bound)
        n->activation = n->lower_bound;
    else
        n->activation = new_value;
}

int fired(neuron *n) {
    return n->activation > n->fire_threshold;
} 

// Ticks a neurons activation towards it's
// resting value.
void decay(neuron *n) {
    float gap = n->activation - n->resting_value;
    // compute decay delta from gap.
    float push = (n->decay_rate * gap) * -1;
    // stimulate neuron with normalized value.
    stimulate(n, push);
}

neuron create_neuron(
    float act,
    float decay,
    float rest,
    float fire,
    float up,
    float low
        ) {
    neuron n = {
        act,
        decay,
        rest,
        fire,
        up,
        low
    };
    return n;
}
