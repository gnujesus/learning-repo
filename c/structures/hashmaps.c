#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
  int key;
  char *value;
  struct node_t *next;
} node_t;

typedef struct hashtable_t {
  size_t capacity;
  size_t size;
  node_t **bucket; // just another way of saying "items"
} hashtable_t;

int hash(char val[], size_t capacity) {
  int size_of_val = strlen(val);
  int final_val = pow(size_of_val, 4) * 3;

  // This is ok but can be out of bounds
  return final_val;
  
  // To keep it in bounds
  // return final_val % capacity;
}

void map(int index, node_t **head) {}

node_t *create_node(int key, char value[], node_t *head) {


  // NODE CREATION

  // Create new node
  node_t *new = malloc(sizeof(node_t));

  // Assign key
  new->key = key;

  // Allocate space for the value
  new->value = malloc(strlen(value) + 1);

  // Assign value
  strcpy(new->value, value);

  // Next value is null, so now the new value is the tail
  new->next = NULL;

  if(head == NULL){
    return new;
  }


  // APPEND TO THE END OF THE LIST

  node_t *temp = head;

  // if the next value is null, then we're on the tail
  while (temp->next != NULL){
    temp = temp->next;
  }

  temp->next = new;
  return head;


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
    node_t* head = NULL;

    head = create_node(1, "Jon", head);
    head = create_node(2, "Arya", head);
    head = create_node(3, "Bran", head);

    printList(head);  // Output: 1 - 2 - 3 -

    return 0;
}
