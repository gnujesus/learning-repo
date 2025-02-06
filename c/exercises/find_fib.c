#include <stdio.h>
#include <stdlib.h>

void findFib(int term) {
  long *arr = malloc((term + 1) * sizeof(long));

  // arr has to be allocated
  if (arr == NULL) {
    printf("Memory allocation failed... \n");
    return;
  }

  arr[0] = 0;
  arr[1] = 1;

  if (term == 1 || term == 2) {
    printf("%ld\n", arr[term - 1]);
    free(arr);
    return;
  }

  for (int i = 2; i <= term; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  for (int i = 0; i <= term; i++) {
    printf("%ld ", arr[i]);
  }

  // NEVER forget to free the memory
  free(arr);
}

int main() {
  // Works up to fib93, then it's unexpected behavior.
  // Don't know how to work through this.

  int input = 0;

  printf("What number of the sequence would you like to find? ");

  if (scanf("%d", &input) < 0) {
    printf("Invalid...\n");
    return 1;
  }

  findFib(input);
  printf("\n");
  return 0;
}
