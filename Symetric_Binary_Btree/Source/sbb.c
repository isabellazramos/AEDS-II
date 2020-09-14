#include "../Header/sbb.h"

void initializeSBB(PointerType *Node)
{
    *Node == NULL;
}

void insertSBB(PointerType *Node, RegType Key)
{
    short End;
    SlopeType Slope;
    printf("insert sbb");
    iinsertSBB(Key, Node, &Slope, &End);
}

void iinsertSBB(RegType Key, PointerType *Node, SlopeType *Slope, short *End)
{
    if (*Node == NULL)
    {
        *Node = (PointerType)malloc(sizeof(NodeType));
        *Slope = Horizontal;
        (*Node)->Reg = Key;
        (*Node)->BitL = Vertical;
        (*Node)->BitR = Vertical;
        (*Node)->Left = NULL;
        (*Node)->Right = NULL;
        *End = FALSE;
        return;
    }

    if (Key.Key < (*Node)->Reg.Key)
    {

        iinsertSBB(Key, &(*Node)->Left, &(*Node)->BitL, End);

        if (*End)
            return;

        if ((*Node)->BitL != Horizontal)
        {
            *End = TRUE;
            return;
        }

        if ((*Node)->Left->BitL == Horizontal)
        {
            LL(Node);
            *Slope = Horizontal;
            return;
        }

        if ((*Node)->Left->BitR == Horizontal)
        {
            LR(Node);
            *Slope = Horizontal;
        }

        return;
    }
/*
    if (Key.Key == (*Node)->Reg.Key)
    {
        printf("Error: the key is in the tree\n");
        *End = TRUE;
        return;
    }
*/
    iinsertSBB(Key, &(*Node)->Right, &(*Node)->BitR, End);

    if (*End)
        return;

    if ((*Node)->BitR != Horizontal)
    {
        *End = TRUE;
        return;
    }

    if ((*Node)->Right->BitR == Horizontal)
    {
        RR(Node);
        *Slope = Horizontal;
        return;
    }

    if ((*Node)->Right->BitL == Horizontal)
    {
        RL(Node);
        *Slope = Horizontal;
    }
}

void printSBB(PointerType Node)
{
    if (Node != NULL)
    {
        printSBB(Node->Left);
        printf("%d\n", Node->Reg.Key);
        printSBB(Node->Right);
    }
}

void LL(PointerType *Node)
{
    PointerType Node1;
    Node1 = (*Node)->Left;
    (*Node)->Left = Node1->Right;
    Node1->Right = *Node;
    Node1->BitL = Vertical;
    (*Node)->BitL = Vertical;
    *Node = Node1;
}
void LR(PointerType *Node)
{
    PointerType Node1, Node2;
    Node1 = (*Node)->Left;
    Node2 = Node1->Right;
    Node1->BitR = Vertical;
    (*Node)->BitL = Vertical;
    Node1->Right = Node2->Left;
    Node2->Left = Node1;
    (*Node)->Left = Node2->Right;
    Node2->Right = *Node;
    *Node = Node2;
}
void RR(PointerType *Node)
{
    PointerType Node1;
    Node1 = (*Node)->Right;
    (*Node)->Right = Node1->Left;
    Node1->Left = *Node;
    Node1->BitR = Vertical;
    (*Node)->BitR = Vertical;
    *Node = Node1;
}
void RL(PointerType *Node)
{
    PointerType Node1, Node2;
    Node1 = (*Node)->Right;
    Node2 = Node1->Left;
    Node1->BitL = Vertical;
    (*Node)->BitR = Vertical;
    Node1->Left = Node2->Right;
    Node2->Right = Node1;
    (*Node)->Right = Node2->Left;
    Node2->Left = *Node;
    *Node = Node2;
}

