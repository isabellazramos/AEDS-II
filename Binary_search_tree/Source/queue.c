#include "../Header/queue.h"

void initializeQueue(QueueT *Queue){
    Queue->Front = (Pointer)malloc(sizeof(CellT));
    Queue->Behind = Queue->Front;
    Queue->Front->Next = NULL;
}

int checkEmptyQueue(QueueT Queue){
    return (Queue.Front == Queue.Behind);
}

void toQueue(QueueT *Queue, ItemT Item){
    Queue->Behind->Next= (Pointer)malloc(sizeof(CellT));
    Queue->Behind = Queue->Behind->Next;
    Queue->Behind->Item = Item;
    Queue->Behind->Next = NULL;

}
void deQueue(QueueT *Queue, ItemT *Item){
    Pointer Aux;
    if(checkEmptyQueue(*Queue)){
        printf("Error: The queue is empty.\n");
        return;
    }
    Aux = Queue->Front;
    Queue->Front = Queue->Front->Next;
    *Item = Queue->Front->Item;
    free(Aux);
}
