#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0

typedef struct RegType
{
    int Key;
}RegType;

typedef enum{
    Vertical, Horizontal
}SlopeType;

typedef struct NodeType *PointerType;
typedef struct NodeType{
    RegType Reg;
    PointerType Left, Right;
    SlopeType BitL,BitR;
}NodeType;

void initializeSBB(PointerType *Node);
void insertSBB(PointerType *Node, RegType Key);
void iinsertSBB(RegType Key, PointerType *Node,SlopeType *Slope, short *End);
void LL(PointerType *Node);
void LR(PointerType *Node);
void RR(PointerType *Node);
void RL(PointerType *Node);
void printSBB(PointerType Node);
void mainmenu();
void leftShort( PointerType *Node, short *End);
void rightShort(PointerType *Node, short *End);
void antecessor(PointerType Aux, PointerType *Node,short *End);
void removeSBB(RegType Reg,PointerType *Node);
void iremoveSBB(RegType Reg,PointerType *Node,short *End);

