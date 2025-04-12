#ifndef LIST_H
#define LIST_H

typedef struct List List;

List *list_create();

void *list_first(List *L);

void *list_next(List *L);

void list_pushFront(List *L, void *dato);

void list_pushBack(List *L, void *dato);

void list_pushCurrent(List *L, void *dato);

void *list_popFront(List *L);

void *list_popBack(List *L);

void *list_popCurrent(List *L);

void list_clean(List *L);

void list_sortedInsert(List *L, void *data,
                       int (*lower_than)(void *data1, void *data2));

int list_size(List* L);

#endif
