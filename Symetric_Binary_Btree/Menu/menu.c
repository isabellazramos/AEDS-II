#include "../Header/sbb.h"

void mainmenu(){
    NodeType *Tree;
    RegType Reg,Aux;
    int option = -1;

    initializeSBB(&Tree);

    while (option != 0)
    {   
        printf("\n-----------------------------------------------------------------\n"); 
        printf("Choose one of the options below by typing the respective number:\n");
        printf("1 - insert into the tree\n");
        printf("2 - print\n");
        printf("\n0 - exit\n");
        printf("-----------------------------------------------------------------\n");

        scanf("%d",&option);

        /*if(option == 1){
            
            printf("\nThe tree has been initialized.\n");
        }*/
        if(option == 1){
            printf("\nType the key you want to insert into the tree:");
            scanf("%d",&Reg.Key);
            insertSBB(&Tree,Reg);
            printf("The key %d has been successfully inserted!\n",Reg.Key);
        }
        if(option == 2){
            if(Tree ==  NULL){
                printf("The tree is empty.\n");
            }else
            {
                printf("Printing in order:\n");
                printSBB(Tree);
            }
        }
        
    }
    
}
