#include "../Header/binarysearchtree.h"

void mainmenu(){
    NodeType *Tree;
    RegType Reg,Aux;
    int option = -1;

    initializeBST(&Tree);

    while (option != 0)
    {   
        printf("\n-----------------------------------------------------------------\n"); 
        printf("Choose one of the options below by typing the respective number:\n");
        printf("1 - insert into the tree\n");
        printf("2 - print order\n");
        printf("3 - print pre order\n");
        printf("4 - print post order\n");
        printf("5 - find a key in the tree\n");
        printf("6 - tree height\n");
        printf("7 - remove key from tree\n");
        printf("8 - print BFS\n");
        printf("9 - number of nodes\n");
        printf("10 - biggest key.\n");
        printf("11 - depth.\n");
        printf("\n0 - exit\n");
        printf("-----------------------------------------------------------------\n");

        scanf("%d",&option);

        /*if(option == 1){
            
            printf("\nThe tree has been initialized.\n");
        }*/
        if(option == 1){
            printf("\nType the key you want to insert into the tree:");
            scanf("%d",&Reg.Key);
            insertBST(&Tree,Reg);
            printf("The key %d has been successfully inserted!\n",Reg.Key);
        }
        if(option == 2){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }else
            {
                printf("Printing in order:\n");
                printOrder(Tree);
            }
        }
        if(option == 3){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }
            else
            {
                printf("Printing in pre-order:\n");
                printPreOrder(Tree);
            }
        }
        if(option == 4){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }
            else
            {
                printf("Printing in post order:\n");
                printPostOrder(Tree);
            }
            
        }
        if(option == 5){
            printf("Type which key you want to find in the tree:");
            scanf("%d",&Aux.Key);
            searchingForKey(Tree,Aux);
        }
        if(option == 6){
            treeHeightResult(Tree);
        }
        if(option == 7){
            printf("\nType the key you want to remove into the tree:");
            scanf("%d",&Reg.Key);
            removeBST(&Tree,Reg);
            printf("The key %d has been successfully removed!\n",Reg.Key);
        }
        if(option == 8){
            printBFS(Tree);
        }
        if(option == 9){
            int numberNodes = numberOfNodes(Tree);
            printf("The tree has %d node(s).\n",numberNodes);
        }
        if(option == 10){
            int bigKey = biggestKey(Tree);
            if(Tree == NULL){
                printf("The tree is empty\n");
            }
            else
            {
               printf("The biggest key in the tree is %d.\n",bigKey);
            }

            
        }
        if(option == 11){
            printf("Type which key you want to find in the tree:");
            scanf("%d",&Aux.Key);
            depthKey(Tree,Aux.Key);
        }
    }
    
}
