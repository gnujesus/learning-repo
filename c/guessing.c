#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[50];
  char major[50];
  int age;
  double gpa;
};

int main() {
  int secretNumber = 5;
  int guess;

  int amountOfGuesses = 0;

  while (guess != secretNumber) {
    if (amountOfGuesses > 0 && amountOfGuesses < 3) {
      printf("Try again!...\n");
    }

    if (amountOfGuesses >= 3) {
      printf("YOU LOSE D:<!");
      return 0;
    }

    printf("Enter a number: ");
    scanf("%d", &guess);

    amountOfGuesses++;
  }

  printf("YOU WIN :D!");
  return 0;
}
