#include <stdio.h>
#include <string.h>

int main() {
  char characters[] = "kla  j sdla \nsjd \t";

  int spaces = 0;
  int tabs = 0;
  int newLines = 0;

	// applied suggestion from deepseek to use strlen() instead of manually calculating
  // for (int i = 0; i < sizeof(characters) / sizeof(char); i++) {
  for (int i = 0; i < strlen(characters); i++) {

		// printf("%c \n", characters[i]);

    switch (characters[i]) {
    case '\n':
      newLines++;
      break;

    case '\t':
      tabs++;
      break;

    case ' ':
      spaces++;
      break;
    }
  }

	printf("Spaces: %d \nTabs: %d \nNew Lines: %d\n", spaces, tabs, newLines);
}
