#include "tst.h"

int main() 
{ 
    TipoApontador Arvore; 
    TipoChave Palavra[50];
    
    int op = -1;

    inicializaTST(&Arvore);

    while (op != 0)
    {
        printf("\n-----------------------------------------------------------------\n"); 
        printf("Escolha uma das opções abaixo digitando o número correspondente:\n");
        printf("1 - Inserir na árvore\n");
        printf("2 - Imprimir\n");
        printf("\n0 - exit\n");
        printf("-----------------------------------------------------------------\n");

        scanf("%d",&op);

        if(op == 1 ){
            printf("\nDigite a palavra que deseja inserir na árvore:");
            scanf("%s",Palavra);
            insereTST(&Arvore,Palavra);
        }
        if(op == 2){
            imprimeTST(Arvore);
        }
    }
    

    return 0; 
} 