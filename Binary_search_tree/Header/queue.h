#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

typedef struct Cell *Pointer;
typedef struct Cell{
    PointerType Item;
    struct Cell *Next;
}CellT;

typedef struct QueueT{
    Pointer Front;
    Pointer Behind;
}QueueT;

void initializeQueue(QueueT *Queue);
int checkEmptyQueue(QueueT Queue);
void toQueue(QueueT *Queue, PointerType Item);
void deQueue(QueueT *Queue, PointerType *Item);