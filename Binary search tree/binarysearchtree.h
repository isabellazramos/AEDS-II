#include <stdio.h>
#include <stdlib.h>

typedef long KeyType;
typedef struct RegType{
    KeyType Key;
}RegType;

typedef struct NodeType *PointerType;
typedef struct NodeType{
    RegType Reg;
    PointerType Left, Right;
}NodeType;


void initializeBST(PointerType *Node);
void insertBST(PointerType *Node, RegType Reg);
void printOrder(PointerType Node);
void printPreOrder(PointerType Node);
void printPostOrder(PointerType Node);