#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void push_front(Node **head, int num) {
  Node *key = (Node*) malloc(sizeof(Node));
  key->value = num;
  key->next = (*head);
  (*head) = key;
  printf("%d", num);
  printf("\n");
}

void pop_front(Node **head) {
  Node* ear = NULL;
  int val;
  if (head == NULL) {
    printf("empty");
  } else {
    ear = (*head);
    val = ear->value;
    (*head) = (*head)->next;
    free(ear);
    printf("%d", val);
  }
  printf("\n");
}

Node* Last(Node *head) {
  if (head == NULL) {
    return NULL;
  }
  while (head->next) {
   head = head->next;
  }
  return head;
}

void push_back(Node **head, int value) {

  Node *last = Last(*head);
  Node *ear = (Node*) malloc(sizeof(Node));
  ear->value = value;
  ear->next = NULL;
  if (last) {
    *head = ear;
  } else {
    last->next = ear;
  }
  printf("%d", value);
  printf("\n");
}

void peek_front(Node *head){
 if (head) {
 int a = head->value;
 printf("%d", a);
 } else {printf("empty");}
 printf("\n");
}

void peek_back(Node *head){
 Node *last = Last(head);
 if (last) {
 int a = last->value;
 printf("%d", a);
 } else {printf("empty");}
 printf("\n");
}

void size(Node *head){
  int i = 0;
  for(i; head; i++ ){
    head = head->next;
  }
  printf("%d", i);
  printf("\n");
}

void clear(Node **head){
  Node *b = NULL;
  while(*head){
    b = (*head)->next;
    free(*head);
    *head = b;
  }
  printf("empty");
  printf("\n");
}

void dump(Node *head){
  if (!head) {printf("empty");}
  else { 
    while (head) {
    printf("%d ", head->value);
    head = head->next;
    };
  }
  printf("\n");
}

int main(void) {

  Node *head = NULL;
  char OP[11] = ""; 

  while (scanf("%s", OP) == 1){ 

    if (!strcmp(OP, "push-front")){ 
      int num = 0; 
      scanf("%d", &num); 
      push_front(&head, num);
      continue; 
    } 
    if (!strcmp(OP, "push-back")){
      int num = 0; 
      scanf("%d", &num);  
      push_back(&head, num);
      continue; 
    } 
    if (!strcmp(OP, "pop-front")){ 
      pop_front(&head);
      continue; 
    } 
 
    if (!strcmp(OP, "peek-front")){ 
      peek_front(head);
      continue; 
    } 
    if (!strcmp(OP, "peek-back")){  
      peek_back(head);
      continue; 
    } 
    if (!strcmp(OP, "size")){ 
      size(head);
      continue; 
    } 
    if (!strcmp(OP, "clear")){ 
      clear(&head);
      continue; 
    } 
    if (!strcmp(OP, "dump")){ 
      dump(head);
      continue; 
    }
  printf("error unknown operation %s\n", OP); 
  return 1; 
  } 
  return 0; 
}