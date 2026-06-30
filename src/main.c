#include "d_array.h"

int main()
{
    DynamicArray d_array;
    initArray(&d_array, 5); // Pass pointer, plus size of 5.
    
    // Add elements..
    // Should trigger resize!
    for (size_t i = 0; i < 25; i++) {
        push(&d_array, i);
    }

    printf("%i\n", get(&d_array, 24));
    printf("%i\n", get(&d_array, 25));
    printf("%i\n", get(&d_array, 26));

    // Checks:
    printf("len: %zu\ncap: %zu\n", d_array.len, d_array.capacity);

    // Free
    freeArray(&d_array);
    return 0;
}
