#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *L = (List*) malloc(sizeof(List));
  assert(L != NULL);
  L->head = NULL;
  L->tail = NULL;
  L->current = NULL;
  return L;
}

void * firstList(List * list){
  if(list->head == NULL){
    list->current = NULL;
    return NULL;
  }
  list->head = list->current;
  
  return list->current->data;
}

void *nextList(List *list) {
    if (list->head == NULL || list->current == NULL || list->current->next == NULL) {
        list->current = NULL;
        return NULL;
    }
    list->current = list->current->next;
    return list->current->data;
}

void *lastList(List *list){
    if(list->head == NULL) {
        list->current = NULL;
        return NULL;
    }

    Node *aux = list->head; 
    while(aux->next != NULL){
        aux = aux->next;
    }
    list->current = aux;
    return aux->data;
}


void *prevList(List *list) {
  if (list->head == NULL || list->current == NULL || list->current->prev == NULL) {
      return NULL;
  }

  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *aux = createNode(data);
  
  if(list->head == NULL){
    list->head = aux;
    list->tail = aux;
  }
  else{
    aux->next = list->head;
    list->head->prev = aux;
    list->head = aux;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *aux = createNode(data);
  if(list->current->next == NULL){
    list->current->next = aux;
  }
  else{
    aux->next = list->current->next;
    list->current->next->prev = aux;
    list->current->next = aux;
    aux->prev = list->current;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}