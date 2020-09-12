#include "../Header/queue.h"

void initializeBST(PointerType *node){
    *node = NULL;
}

void insertBST(PointerType *Node, RegType Reg){
    if(*Node == NULL){
        *Node = (PointerType)malloc(sizeof(NodeType));
        (*Node)->Reg = Reg;
        (*Node)->Left = NULL;
        (*Node)->Right = NULL;
        return;
    }
    if(Reg.Key < (*Node)->Reg.Key){
        insertBST(&(*Node)->Left,Reg);
        return;
    }
    if(Reg.Key > (*Node)->Reg.Key){
        insertBST(&(*Node)->Right,Reg);
        return;
    }
}

void printOrder(PointerType Node){
    if(Node == NULL){
        return;
    }
    printOrder(Node->Left);
    printf("%d\n", Node->Reg.Key);
    printOrder(Node->Right);
}

void printPreOrder(PointerType Node){
    if(Node == NULL){
        return;
    }
    printf("%d\n", Node->Reg.Key);
    printOrder(Node->Left);
    printOrder(Node->Right);
}

void printPostOrder(PointerType Node){
    if(Node == NULL){
        return;
    }
    printOrder(Node->Left);
    printOrder(Node->Right);
    printf("%d\n", Node->Reg.Key);
}

void searchingForKey(PointerType Node, RegType Key){

    if(Node != NULL){
        if(Node->Reg.Key == Key.Key){
            printf("The key has been found!\n");
        }
        if(Key.Key < Node->Reg.Key){
            searchingForKey(Node->Left,Key);
        }
        if(Key.Key > Node->Reg.Key){
            searchingForKey(Node->Right,Key);
        }
    }else
    {
        printf("The key was not found :( \n");
    }
    
}

int treeHeight(PointerType Node){
    if(Node == NULL){
        return -1;
    }
    else{
        int heightLeft = treeHeight(Node->Left);
        int heightRight = treeHeight(Node->Right);
        if(heightLeft < heightRight) return (heightRight + 1);
        else return (heightLeft + 1);
    }
}

void treeHeightResult(PointerType Node){

    printf("The height of the tree is %d.\n",treeHeight(Node));

}

void removeBST(PointerType *Node, RegType Reg){
    PointerType Aux;
    
    if(*Node == NULL){
        printf("Element does not exist or the tree is empty.\n");
        return;

    }
    else
    {
        if(Reg.Key < (*Node)->Reg.Key){
            removeBST(&(*Node)->Left,Reg);
            return;
        }
        if(Reg.Key > (*Node)->Reg.Key){
            removeBST(&(*Node)->Right,Reg);
            return;
        }
        if(((*Node)->Right == NULL) && ((*Node)->Left != NULL)){
            Aux = *Node;
            *Node = (*Node)->Left;
            free(Aux);
            return;
        }
        if(((*Node)->Right != NULL) && ((*Node)->Left != NULL)){
            predecessor(*Node,&(*Node)->Left);
            return;
        }
        if(((*Node)->Right != NULL) && ((*Node)->Left == NULL)){
            Aux = *Node;
            *Node = (*Node)->Right;
            free(Aux);
            return;
        }        
    }
    
}

void predecessor(PointerType q, PointerType *r){
    PointerType aux;
    if((*r)->Right != NULL){
        predecessor(q,&(*r)->Right);
        return;
    }
    q->Reg = (*r)->Reg;
    aux = *r;
    *r = (*r)->Left;
    free(aux);
}

void printBFS(PointerType Node){
    QueueT queue;
    initializeQueue(&queue);
    if(Node != NULL){
        toQueue(&queue,Node);
        while (!checkEmptyQueue(queue))
        {   
            deQueue(&queue,&Node);
            printf("%d", Node->Reg.Key);
            if(Node->Left != NULL){
                toQueue(&queue,Node->Left);
            }
            if(Node->Right != NULL){
                toQueue(&queue,Node->Right);
            }
        }
        
    }else{
        printf("The tree is empty\n");
    }
}