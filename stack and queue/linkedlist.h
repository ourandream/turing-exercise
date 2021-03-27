#include <stdio.h>
#include <stdlib.h>

typedef struct _LNode{
  int data;
  struct _LNode* next; 
}LNode;//取别名

// create an empty single linked list (without head node)
// return the head
LNode* listInit() {
  return NULL;
}

void printList(LNode* head) {
  if (!head) {
    printf("[Empty]\n");
    return;
  }
  for (LNode* i=head; i; i=i->next) {
    printf("%d ", i->data);
  }
  printf("\n");
}

// create a new LNode with given data
LNode* createLNode(int data) {
  LNode* newNode = (LNode*)malloc(sizeof(LNode));
  newNode->data = data;
  return newNode;
}

// insert node in pos (which there are pos nodes before node)
// insert at the end if len(list)<=pos
// return new head
LNode* listInsert(LNode* head, int pos, LNode* node) {
  if (!pos) {
    node->next = head;
    return node;
  }

  LNode* tmp = head;
  for (int i=0; tmp->next && i<pos-1; i++) {
    tmp = tmp->next;
  }
  
  node->next = tmp->next;
  tmp->next = node;
  return head;
}

// search first node with data
// return such node or NULL if not found 
LNode* listSearchData(LNode* head, int data) {
  for (LNode* i=head; i; i=i->next) {
    if (i->data==data) {
      return i;
    }
  }
  return NULL;
}

// delete node in pos (which there are pos nodes before node)
// do nothing if len(list)<pos
LNode* listDelete(LNode* head, int pos) {
  LNode* tmp = head;
  if (!pos) {
    tmp = tmp->next;
    free(head);
    return tmp;
  }

  int i;
  for (i=0; tmp->next && i<pos-1; i++) {
    tmp = tmp->next;
  }
  if (i==pos-1) {
    LNode* d = tmp->next;
    tmp->next = d->next;
    free(d);
  }
  return head;
}

LNode* listDestroy(LNode* head) {
  LNode* tmp = head;
  while (tmp) {
    tmp = listDelete(tmp, 0);
  }
  return tmp;
}