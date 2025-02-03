#include <stdio.h>
#include <string.h>

void deleteChar(char *str, int index) {
  int length = strlen(str);

  if (index < 0 || index > length) {
    printf("INDEX OUT OF BOUNDS");
    return;
  }

  for (int i = index; i < length - 1; i++) {
    str[i] = str[i + i];
  }

  str[length - 1] = '\0';
}

int main() {
  char str[] = "parangarigutilimicuaro";
  int length = strlen(str);

  while (length > 0) {
    char buffer = str[0];
    int count = 0;

    for (int j = 0; j < length;) {
      if (buffer == str[j]) {
        count++;
        deleteChar(str, j);
        length--;
      } else {
        j++;
      }
    }

    printf("%c --> ", buffer);
    for (int k = 0; k < count; k++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}
