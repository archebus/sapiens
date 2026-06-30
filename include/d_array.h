#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdio.h>

typedef struct {
    int *array; // Pointer to array
    size_t len; // Current # of elements
    size_t capacity; // Total number of elements
} DynamicArray;

void initArray(DynamicArray *d_array, size_t initialSize);
void resizeArray(DynamicArray *d_array, size_t new_cap);
void freeArray(DynamicArray *d_array);
void push(DynamicArray *d_array, int element);
int get(DynamicArray *d_array, size_t index);

#endif
