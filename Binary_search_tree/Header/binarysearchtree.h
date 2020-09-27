#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void initializeBST(PointerType *Node);
void insertBST(PointerType *Node, RegType Reg);
void printOrder(PointerType Node);
void printPreOrder(PointerType Node);
void printPostOrder(PointerType Node);
void searchingForKey(PointerType Node, RegType Key);
int treeHeight(PointerType Node);
void treeHeightResult(PointerType Node);
void removeBST(PointerType *Node, RegType Reg);
void predecessor(PointerType q, PointerType *r);
void printBFS(PointerType Node);
int numberOfNodes(PointerType Node);
int biggestKey(PointerType Node);
void depthKey(PointerType Node,int Key);
void depthKeyAux(PointerType Node,int Key, int depth);
void mainmenu();