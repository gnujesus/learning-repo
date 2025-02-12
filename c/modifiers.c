#include <stdio.h>


// global -> init 0
int global_var;

// NOTE:
// declaration, but not definition
// variable from another file reused here
// ---
// Compiler must know about the other files to link (linker)
// gcc modifiers.c modifiers_2.c -o modifiers
extern int a;

int main() {

  // auto -> garbage init value
  int not_auto;
  auto int auto_var;

  printf("Not Auto: %d", not_auto);
  printf("\n");
  printf("Auto: %d", auto_var);
  printf("\n");
  printf("External variable: %d", a);
  return 0;
}
