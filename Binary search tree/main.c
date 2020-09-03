#include "binarysearchtree.h"

int main(){
    NodeType *Tree;
    RegType Reg,Aux;
    int option = -1;

    printf("********************************\n");
    printf("*    bst tree implementation   *\n");
    printf("*    made by @isabellazramos   *\n");
    printf("*                              *\n");
    printf("* based on the implementation  *\n");
    printf("*       made by ziviani        *\n");
    printf("********************************\n\n");


    while (option != 0)
    {   
        printf("\nChoose one of the options below by typing the respective number:\n");
        printf("-----------------------------------------------------------------\n");
        printf("1 - initialize the tree\n");
        printf("2 - insert into the tree\n");
        printf("3 - print order\n");
        printf("4 - print pre order\n");
        printf("5 - print post order\n");
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
                printf("\n");
                printOrder(Tree);
            }
        }
        if(option == 4){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }
            else
            {
                printf("\n");
                printPreOrder(Tree);
            }
        }
        if(option == 5){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }
            else
            {
                printf("\n");
                printPostOrder(Tree);
            }
            
        }
    }
    
 
}