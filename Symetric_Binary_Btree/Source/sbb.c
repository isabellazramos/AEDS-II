#include "../Header/sbb.h"

void initializeSBB(PointerType *Node)
{
    *Node == NULL;
}

void insertSBB(PointerType *Node, RegType Key)
{
    short End;
    SlopeType Slope;
    iinsertSBB(Key, Node, &Slope, &End);
}

void iinsertSBB(RegType Key, PointerType *Node, SlopeType *Slope, short *End){
  if(*Node == NULL){
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
  if(Key.Key < (*Node)->Reg.Key){
    iinsertSBB(Key, &(*Node)->Left, &(*Node)->BitL, End);
    if(*End)
      return;
    if((*Node)->BitL != Horizontal){
      *End = TRUE;
      return;
    }
    if((*Node)->Left->BitL == Horizontal){
      LL(Node);
      *Slope = Horizontal;
      return;
    }
    if((*Node)->Left->BitR == Horizontal){
      LR(Node);
      *Slope = Horizontal;
    }
    return;
  }
  if(Key.Key <= (*Node)->Reg.Key){
    printf("Erro: Chave já está na árvore\n");
    *End = TRUE;
    return;
  }
  iinsertSBB(Key, &(*Node)->Right, &(*Node)->BitR, End);
  if(*End)
    return;
  if((*Node)->BitR != Horizontal){
    *End = TRUE;
    return;
  }
  if((*Node)->Right->BitR == Horizontal){
    RR(Node);
    *Slope = Horizontal;
    return;
  }
  if((*Node)->Right->BitL == Horizontal){
    RL(Node);
    *Slope = Horizontal;
  }
}


void printSBB(PointerType Node)
{
  if(Node == NULL){
    return;
  }
  else
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

void leftShort( PointerType *Node, short *End){
  PointerType Node1;
  if((*Node)->BitL == Horizontal){
    (*Node)->BitL = Vertical;
    *End = TRUE;
    return;
  }
  if((*Node)->BitR == Horizontal){
    Node1 = (*Node)->Right;
    (*Node)->Right = Node1->Left;
    Node1->Left = *Node;
    *Node = Node1;
    
    if((*Node)->Left->Right->BitL == Horizontal){
      RL(&(*Node)->Left);
      (*Node)->BitL = Horizontal;
    }else if ((*Node)->Left->Right->BitR == Horizontal)
    {
      RR(&(*Node)->Left);
      (*Node)->BitL = Horizontal;
    }

    *End = TRUE;
    return;    
  }
  (*Node)->BitR = Horizontal;
  if ((*Node)->Right->BitL == Horizontal)
  {
    RL(Node);
    *End = TRUE;
    return;
  }
  if((*Node)->Right->BitR == Horizontal)
  {
    RR(Node);
    *End = TRUE;
  }
}

void rightShort(PointerType *Node, short *End){
  PointerType Node1;
  if((*Node)->BitR == Horizontal){
    (*Node)->BitR = Vertical;
    *End = TRUE;
    return;
  }
  if((*Node)->BitL == Horizontal){
    Node1 = (*Node)->Left;
    (*Node)->Left = Node1->Right;
    Node1->Right = *Node;
    *Node = Node1;
    
    if((*Node)->Right->Left->BitR == Horizontal){
      LR(&(*Node)->Right);
      (*Node)->BitR = Horizontal;
    }else if ((*Node)->Right->Left->BitL == Horizontal)
    {
      LL(&(*Node)->Right);
      (*Node)->BitR = Horizontal;
    }

    *End = TRUE;
    return;    
  }
  (*Node)->BitL = Horizontal;
  if ((*Node)->Left->BitR == Horizontal)
  {
    LR(Node);
    *End = TRUE;
    return;
  }
  if((*Node)->Left->BitL == Horizontal)
  {
    LL(Node);
    *End = TRUE;
  }
}

void antecessor(PointerType Aux, PointerType *Node,short *End){
  if((*Node)->Right != NULL){
    antecessor(Aux,&(*Node)->Right,End);
    if(!*End){
      leftShort(Node,End);
      return;
    }
    Aux->Reg = (*Node)->Reg;
    Aux = *Node;
    *Node = (*Node)->Left;
    free(Aux);
    if(*Node !=NULL){
      *End = TRUE;
    }
  }
}

void removeSBB(RegType Reg,PointerType *Node){
  short End;
  iremoveSBB(Reg,Node,&End);
}

void iremoveSBB(RegType Reg,PointerType *Node,short *End){
  NodeType *Aux;
  if(*Node ==  NULL){
    printf("The key is not in the tree.\n");
    *End = TRUE;
    return;
  }
  if(Reg.Key < (*Node)->Reg.Key){
    iremoveSBB(Reg,&(*Node)->Left,End);
    if(!*End){
      leftShort(Node,End);
      return;
    }
  }
  if(Reg.Key > (*Node)->Reg.Key){
    iremoveSBB(Reg,&(*Node)->Right,End);
    if(!*End){
      rightShort(Node,End);
      return;
    }
  }
  *End = FALSE;
  Aux = *Node;
  if(Aux->Right == NULL){
    *Node = Aux->Left;
    free(Aux);
    if(*Node != NULL){
      *End = TRUE;
      return;
    }
  }
  if(Aux->Left == NULL){
    *Node = Aux->Right;
    free(Aux);
    if(*Node != NULL){
      *End = TRUE;
      return;
    }
  }
  antecessor(Aux,&Aux->Left,End);
  if(!*End){
    leftShort(Node,End);
  }
}
