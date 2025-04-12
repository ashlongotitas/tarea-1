#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

struct List {
  Node *head;
  Node *tail;
  Node *current;
  int size;
};

typedef List List;

List *list_create() {
  List *newList = (List *)malloc(sizeof(List));
  if (newList == NULL) {
    return NULL; 
  }
  newList->head = NULL;
  newList->tail = NULL;
  newList->current = NULL;
  newList->size = 0;
  return newList;
}

void *list_first(List *L) {
  if (L == NULL || L->head == NULL) {
    return NULL; 
  }
  L->current = L->head;
  return L->current->data;
}

void *list_next(List *L) {
  if (L == NULL || L->current == NULL || L->current->next == NULL) {
    return NULL; 
  }
  L->current = L->current->next;
  return L->current->data;
}

void list_pushFront(List *L, void *data) {
  if (L == NULL) {
    return; 
  }
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return; 
  }
  newNode->data = data;
  newNode->next = L->head;
  L->head = newNode;
  if (L->tail == NULL) { 
    L->tail = newNode;
  }
  L->size++;
}

void list_pushBack(List *L, void *data) {
  if (L == NULL) {
    return; 
  }
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return; 
  }
  newNode->data = data;
  newNode->next = NULL;
  if (L->tail == NULL) { 
    L->head = newNode;
    L->tail = newNode;
  } else {
    L->tail->next = newNode;
    L->tail = newNode;
  }
  L->size++;
}

void *list_popFront(List *L) {
  if (L == NULL || L->head == NULL) {
    return NULL; // Lista vacía o no inicializada
  }
  Node *temp = L->head;
  L->head = L->head->next;
  if (L->head == NULL) {
    L->tail = NULL; // La lista ahora está vacía
  }
  void *data = temp->data;
  free(temp);
  L->size--;
  return data;
}

void *list_popBack(List *L) {
  if (L == NULL || L->head == NULL) {
    return NULL; // Lista vacía o no inicializada
  }
  if (L->head == L->tail) { // Solo un elemento en la lista
    return list_popFront(L);
  }
  Node *current = L->head;
  while (current->next != L->tail) {
    current = current->next;
  }
  void *data = L->tail->data;
  free(L->tail);
  current->next = NULL;
  L->tail = current;
  L->size--;
  return data;
}

int list_size(List *L){
    return L->size;
}


void list_clean(List *L) {
  if (L == NULL) {
    return; // Lista no inicializada
  }
  Node *current = L->head;
  Node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  L->head = NULL;
  L->tail = NULL;
  L->current = NULL;
  L->size = 0;
}
