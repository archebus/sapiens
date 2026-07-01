#ifndef NEURON
#define NEURON

// The neuron!
// The atomic unit of a pawns brain.
//  activation: the level of stimulation in this neuron.
//  decay_rate: how quickly the neuron returns to resting.
//  resting_value: where this neuron naturally sits.
//  fire_threshold: controls when the neuron will fire.
//  upper_bound: the max value this neuron can reach.
//  lower_bound: the min value this neuron can reach.
//
// These fields can be influenced by a genetic layer
// during init.
typedef struct {
    float activation;
    float decay_rate;
    float resting_value;
    float fire_threshold;
    float upper_bound;
    float lower_bound;
} neuron;

void stimulate(neuron *n, float push);
int fired(neuron *n);
void decay(neuron *n);
neuron create_neuron(
    float act,
    float decay,
    float rest,
    float fire,
    float up,
    float low
);

#endif
