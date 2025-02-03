#include <stdio.h>
#include <string.h>

void deletecharacter(char *str, int index) {
  int length = strlen(str);

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

  char buffer;
  int count = 0;

	int length = strlen(str);

  // go through the string
  for (int i = 0; i < length; i++) {
    buffer = str[i];
    // printf("%s", &str[i]);

    // iterate over the string for each value on the string to count
    for (int j = 0; j < length; j++) {
      if (buffer == str[j]) {
        count++;
      }
    }

    // while there's a character that's the same on the one on buffer, keep
    // deleting it until you find no more.
    for (int j = 0; j < length; j++) {
      while (buffer == str[j]) {
        deletecharacter(str, j);
      }
    }

    /*
     * You can also use this one, but this one doesn't delete all character
     * completely. o stays on buffer.
     */

    // while (buffer == str[i]) {
    //   deletecharacter(str, i);
    // }

    // formatting
    printf("%c --> ", buffer);

    // print each the amount of values on buffer while resetting
    while (count != 0) {
      printf("* ");
      count--;
    }

    printf("\n\nCurrent state of str: %s", str);

    // next on buffer, cuz we don't want everything on one line
    printf("\n");
  }

  return 0;
}
