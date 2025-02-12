#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node_t;

/*
  *
  * Can also be
  *
  *
struct node {
  int value;
  struct node *next;
};

typedef struct node node;
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->val = 2;
  temp->next = new_node;

  *
  */

void printList(node_t *head) {
  node_t *temporaryPtr = head;

  while (temporaryPtr != NULL) {
    printf("%d - ", (*temporaryPtr).value);
    temporaryPtr = (*temporaryPtr).next;
  }
}

node_t *createNewNode(int value) {
  node_t *node = malloc(sizeof(node_t));
  node->value = value;
  node->next = NULL;

  return node;
}

void addToHead(node_t *newNode, node_t **head) {
  newNode->next = *head;
  *head = newNode;
}

void createNewNodeOnHead(int value, node_t **head) {
  node_t *temp;
  temp = createNewNode(value);
  addToHead(temp, &*head);
}

int main() {
  node_t *head;
  node_t *temp;

  temp = createNewNode(32);
  head = temp;

  for(int i = 0; i < 139; i++){
    createNewNodeOnHead(i, &head);
  }

  printList(head);

  return 0;
}
