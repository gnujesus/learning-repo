#include <stdio.h>
#include <stdlib.h>

void findFib(int term) {
  int *arr = malloc((term + 1) * sizeof(term));

  // arr has to be allocated
  if (arr == NULL) {
    printf("Memory allocation failed... \n");
    return;
  }

  arr[0] = 0;
  arr[1] = 1;

  if(term == 1 || term == 2){
  printf("%d\n", arr[term - 1]);
    return;
  }

  for (int i = 2; i <= term; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  printf("%d\n", arr[term]);

  // NEVER forget to free the memory
  free(arr);
}

int main() {
  int input = 0;

  printf("What number of the sequence would you like to find? ");

  if(scanf("%d", &input) < 0){
    printf("Invalid...\n");
    return 1;
  }

  findFib(input);
  return 0;
}
