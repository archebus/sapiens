#include "render.h"
#include "neuron.h"
#include <stdio.h>

const char *green = "\x1b[32m";
const char *reset = "\x1b[0m";

void render_neuron(neuron *n) {
    // TODO: Clamp the bounds to 0 - 10
    // Current init does not guard and
    // may use these higher values?
    
    printf("[");
    if (fired(n))
        printf("%s", green);
    for (int i = 0; i < n->upper_bound; i++) {
        if ((float)i < n->activation)
            printf("#");
        else
            printf(" ");
    }
    printf("%s", reset);
    printf("]\n");
}
