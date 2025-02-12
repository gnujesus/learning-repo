#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

ListNode *reverseList(ListNode *head) {
  ListNode *temp = NULL;
  ListNode *temp2 = NULL;
  ListNode *new_head = head;

  while (1) {
    if (new_head->next == NULL) {
      new_head->next = temp;
      break;
    }

    temp = new_head;
    new_head = new_head->next;
    temp->next = temp2;
    temp2 = temp;
  }

  return new_head;
}

ListNode *createNewNode(int val) {
  ListNode *node = malloc(sizeof(ListNode));
  node->val = val;
  node->next = NULL;

  return node;
}

void printList(ListNode *head) {
  ListNode *temporaryPtr = head;

  while (temporaryPtr != NULL) {
    printf("%d - ", temporaryPtr->val);
    temporaryPtr = temporaryPtr->next;
  }
}

int main() {
  ListNode *head;
  ListNode *temp = malloc(sizeof(ListNode));

  temp->val = 1;
  temp->next = NULL;
  head = temp;

  temp->next = createNewNode(2);
  temp = temp->next;

  temp->next = createNewNode(3);
  temp = temp->next;

  head = reverseList(head);
  printList(head);
}
