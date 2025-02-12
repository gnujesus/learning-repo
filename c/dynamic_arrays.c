#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO: Check for allocation success lol.
// also on realloc pls

typedef struct array {
  size_t capacity;
  size_t size;
  int *items;
} Array;

Array *init_array(size_t capacity) {
  Array *arr = malloc(sizeof(Array));

  arr->capacity = capacity;
  arr->size = 0;
  arr->items = calloc(capacity, sizeof(int));
  return arr;
}

void array_add(Array *arr, int item, int index) {
  // NOTE: Wrong, you don't check for size, you check for capacity
  //
  // if (index + 1 > arr->size) {
  //   arr->items = realloc(arr->items, ((2 * arr->capacity) * sizeof(int)));
  // }

  if (index >= arr->capacity) {
    size_t new_capacity = arr->capacity * 2;
    int *new_items = realloc(arr->items, (new_capacity * sizeof(int)));

    arr->capacity = new_capacity;
    arr->items = new_items;
  }

  arr->items[index] = item;
  arr->size++;
}

int array_get(Array *arr, int index) {
  if (index >= arr->capacity || index < 0) {
    printf("INDEX OUT OF BOUNDS.");
    return -1;
  }

  return arr->items[index];
}

bool array_delete(Array *arr, int index) {
  if (index >= arr->capacity || index < 0) {
    printf("INDEX OUT OF BOUNDS.");
    return false;
  }

  for(int i = index; i < arr->capacity - 1; i++){
    arr->items[index] = arr->items[index + 1];
  }

  size_t new_capacity = arr->capacity--;
  int *new_items = realloc(arr->items, (new_capacity * sizeof(int)));
  arr->size--;
  return true;
}

int main() {
  Array *arr = init_array(5);
  for (int i = 0; i < 129; i++) {
    array_add(arr, i + 1, i);
  }

  printf("Current value in index 18 (before delete): %d\n\n", array_get(arr, 18));

  array_delete(arr, 18);

  printf("Current value in index 18 (after delete): %d\n\n", array_get(arr, 18));

  // NOTE: Wrong freeing order
  /*
   * free(arr);
   * free(arr->items);
   */

  free(arr->items);
  free(arr);
}
