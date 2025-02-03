#include <stdio.h>
#include <string.h>

void deleteChar(char *str, int index) {
  int length = strlen(str);

  if(length == 1){
    str[0] = '\0';
  }

  if (index < 0 || index > length) {
    printf("index out of bounds");
    return;
  }

  for (int i = index; i < length - 1; i++) {
    str[i] = str[i + 1];
  }

  str[length - 1] = '\0';
}

int main() {
  char str[] = "lllooooo";
  printf("String to count: %s \n\n", str);

  int length = strlen(str);

  while (length > 0) {
    char buffer = str[0];
    int count = 0;

    for (int i = 0; i <= length;) {
      printf("Value of i: %d \n\n", i);
      if (buffer == str[i]) {
        count++;
        length--;
        deleteChar(str, i);
      } else {
        i++;
      }
    }

    printf("%c ----> ", buffer);
    for (int i = 0; i < count; i++) {
      printf("* ");
    }
    printf("\n");

    length--;
  }

  printf("\n");

  return 0;
}
