#include "d_array.h"

int main()
{
    DynamicArray my_array;
    initArray(&my_array, 5);
    
    // Add elements..
    // Should trigger resize!
    for (size_t i = 0; i < 25; i++)
        push(&my_array, i);

    for (size_t i = 0; i < my_array.len; i++)
        printf("element: %i\n", my_array.array[i]);

    // Free
    freeArray(&my_array);
    return 0;
}
