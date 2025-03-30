#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
  int key;
  struct node_t *next;
  char value[];
} node_t;

typedef struct hashtable_t {
  size_t capacity;
  size_t size;
  node_t *bucket; // just another way of saying "items"
} hashtable_t;

int hash(char val[], size_t capacity) {
  int size_of_val = strlen(val);
  int final_val = pow(size_of_val, 4) * 3;
  return final_val;
  // int index = (int)(final_val % capacity);
}

void map(int index, node_t **head) {}

node_t *create_node(int key, char value[], node_t *head) {

  //somewhere around here
  node_t *temp = head->next;

  // if the next value is null, then we're on the tail
  while (temp->next != NULL){
    temp = temp->next;
  }

  node_t *new = malloc(sizeof(node_t));
  new->key = key;
  strcpy(new->value, value);
  new->next = NULL;

  temp->next = new;
  return new;
  // I'm thinking on memory implications now
  // i mean, is this a copy? what assures me this is really being added to the tail?
  // oh yeah, now i'm sure
  // since I'm using temp->next, it doesn't matter if temp is a copy of the tail, since I'm directly modifying the next value of the tail
  // using ->, so yeah, let's print it
}

void printList(node_t *head) {
  node_t *temp = head;

  while (temp != NULL) {
    printf("%d - ", temp->key);
    temp = temp->next;
  }
}

int main() {
  char value[] = "Jon";
  int hash_code = hash(value, 5);

  node_t *head;
  node_t *temp;

  temp = create_node(hash_code, value, head);
  head = temp;

  // where did i fuck it up?

  printList(head);

  free(temp);
}
