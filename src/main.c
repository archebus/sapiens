#include "neuron.h"
#include "render.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rand_max = 10;

    // Neuron starting values.
    float base_activation = 2.0;
    float base_decay = 0.1;
    float base_rest = 2.0;
    float base_fire = 6.0;
    float base_upper = 10.0;
    float base_lower = 0.0;

    const size_t neuron_count = 100;
    neuron neurons[neuron_count];
    
    // Creation pass.
    for (size_t i = 0; i < neuron_count; i++) {
        neurons[i] = create_neuron(
            base_activation,
            base_decay,
            base_rest,
            base_fire,
            base_upper,
            base_lower
                );
    }

    // Push pass with rand()
    for (size_t i = 0; i < neuron_count; i++) {
        float push = rand() % (rand_max + 1);
        stimulate(&neurons[i], push);
    }

    // Render neurons
    for (size_t i = 0; i < neuron_count; i++) {
        printf("N:%2zu ", i);
        render_neuron(&neurons[i]);
    }

    return 0;
}
