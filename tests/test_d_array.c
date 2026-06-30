#include "d_array.h"
#include <assert.h>

void test_dArray_init() {
    // Contract: arrays are init'd with correct memory and size.

    // Arrange
    DynamicArray d_array;

    // Act
    initArray(&d_array, 5);

    // Assert
    assert(d_array.len == 0);
    assert(d_array.capacity == 5);
    freeArray(&d_array);
}

void test_dArray_push_single() {
    // Contract: can store elements in an array with push.

    // Arrange
    DynamicArray d_array;

    // Act
    initArray(&d_array, 5);
    push(&d_array, 10);

    // Assert
    assert(d_array.array[0] == 10);
    freeArray(&d_array);
}

void test_dArray_push_realloc() {
    // Contract: push resizes the array appropriately.

    // Arrange
    DynamicArray d_array;

    // Act
    initArray(&d_array, 5);
    for (size_t i = 0; i < d_array.capacity; i++) {
        push(&d_array, i);
    }
    // Assert
    // Array should be full after loop.
    assert(d_array.len == 5);
    assert(d_array.capacity == 5);

    // Push one more element.
    push(&d_array, 6);

    // Len should increment, cap should double.
    assert(d_array.len == 6);
    assert(d_array.capacity == 10);
    freeArray(&d_array);
}

void test_dArray_get() {
    // Contract: can retrive elements of an array.

    // Arrange
    DynamicArray d_array;

    // Act
    initArray(&d_array, 5);
    push(&d_array, 10);

    // Assert
    assert(get(&d_array, 0) == 10);
    freeArray(&d_array);
}
