#include "binarysearchtree.h"

void mainmenu(){
    NodeType *Tree;
    RegType Reg,Aux;
    int option = -1;

    while (option != 0)
    {   
        printf("\n-----------------------------------------------------------------\n"); 
        printf("Choose one of the options below by typing the respective number:\n");
        printf("1 - initialize the tree\n");
        printf("2 - insert into the tree\n");
        printf("3 - print order\n");
        printf("4 - print pre order\n");
        printf("5 - print post order\n");
        printf("6 - find a key in the tree\n");
        printf("7 - tree height");
        printf("\n0 - exit\n");
        printf("-----------------------------------------------------------------\n");

        scanf("%d",&option);

        if(option == 1){
            initializeBST(&Tree);
            printf("\nThe tree has been initialized.\n");
        }
        if(option == 2){
            printf("\nType the key you want to insert into the tree:");
            scanf("%d",&Reg.Key);
            insertBST(&Tree,Reg);
            printf("The key %d has been successfully inserted!\n",Reg.Key);
        }
        if(option == 3){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }else
            {
                printf("Printing in order:\n");
                printOrder(Tree);
            }
        }
        if(option == 4){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }
            else
            {
                printf("Printing in pre-order:\n");
                printPreOrder(Tree);
            }
        }
        if(option == 5){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }
            else
            {
                printf("Printing in post order:\n");
                printPostOrder(Tree);
            }
            
        }
        if(option == 6){
            printf("Type which key you want to find in the tree:");
            scanf("%d",&Aux.Key);
            searchingForKey(Tree,Aux);
        }
        if(option == 7){
            treeHeightResult(Tree);
        }
    }
    
}
