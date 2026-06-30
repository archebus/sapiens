#include <stdio.h>
#include <stdlib.h>
#include "d_array.h"

void initArray(DynamicArray *d_array, size_t initialSize) {
    if (initialSize == 0) {
        // Always init at least some space.
        initialSize = 1;
    }
    d_array->len = 0;
    d_array->capacity = initialSize;
    d_array->array = (int *)malloc(initialSize * sizeof(int));
    if (d_array->array == NULL) {
        // Error on mem alloc failure here.
    }
}

void resizeArray(DynamicArray *d_array, size_t new_cap) {
    int *temp = (int *)realloc(d_array->array, new_cap * sizeof(int));
    if (temp == NULL) {
        // Handle mem alloc failure.
    } else {
        d_array->array = temp;
        d_array->capacity = new_cap;
    }
}

void freeArray(DynamicArray *d_array) {
    free(d_array->array);
    d_array->array = NULL; // Avoids dangling pointer..
}

void push(DynamicArray *d_array, int element) {
    // Double capacity if array at size bounds.
    if (d_array->len == d_array->capacity) {
        size_t new_cap = d_array->capacity * 2;
        resizeArray(d_array, new_cap);
    }
    // len is correct here, as d_array 0 indexed, count is not.
    // Push element
    d_array->array[d_array->len] = element;
    ++d_array->len;
}

int get(DynamicArray *d_array, size_t index) {
    if (index >= d_array->len)
        return -1; // Handle this better later.
    return d_array->array[index];
}
