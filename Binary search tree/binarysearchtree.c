#include "bst_tree.h"

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