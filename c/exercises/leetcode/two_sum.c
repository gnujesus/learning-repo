#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *result = malloc(2 * sizeof(int));
  returnSize = 2;

  for (int i = 0; i < numsSize; i++) {

    result[0] = i;

    for (int j = 0; j < numsSize; j++) {

      if (i == j) {
        continue;
      }

      if (nums[i] + nums[j] == target) {
        result[1] = j;
        return result;
      }
    }
  }

  return NULL;
}

int main() {
  int returnSize = 2;
  int nums[] = {3, 3};
  int target = 6;
  int numsLength = sizeof(nums) / sizeof(nums[0]);
  int *resultPtr = twoSum(nums, numsLength, target, &returnSize);

  for (int i = 0; i < 2; i++) {
    printf("%d ", resultPtr[i]);
  }

  free(resultPtr);
  return 0;
}
