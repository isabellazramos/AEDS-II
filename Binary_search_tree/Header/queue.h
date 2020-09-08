#include <stdio.h>
#include <stdlib.h>

typedef int ItemType;
typedef struct ItemT{
    ItemType Result;
}ItemT;

typedef struct Cell *Pointer;
typedef struct Cell{
    ItemT Item;
    struct Cell *Next;
}CellT;

typedef struct QueueT{
    Pointer Front;
    Pointer Behind;
}QueueT;

void initializeQueue(QueueT *Queue);
int checkEmptyQueue(QueueT Queue);
void toQueue(QueueT *Queue, ItemT Item);
void deQueue(QueueT *Queue, ItemT *Item);
