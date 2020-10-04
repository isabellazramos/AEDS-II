#include "Header/tst.h"

int main() 
{ 
    FILE *pont_arq;
    
    TipoApontador Arvore; 
    TipoChave Palavra[50];
    int op = -1;

    char nomeArquivo[20];

    inicializaTST(&Arvore);

    while (op != 0)
    {   
        printf("\n-----------------------------------------------------------------\n"); 
        printf("Digite uma das opções do menu abaixo:\n");
        printf("1 - Inicializar TST\n");
        printf("2 - Ler arquivo e inserir na árvore\n");
        printf("3 - Printar árvore\n");
        printf("4 - Quantidade de palavras.\n");
        printf("\n0-  Sair\n");
        printf("-----------------------------------------------------------------\n");

        scanf("%d",&op);

        if(op == 1){
            inicializaTST(&Arvore);
        }
        if(op == 2){
            printf("Digite o nome do arquivo:\n");
            scanf("%s",nomeArquivo);
            abrirArquivo(&Arvore,nomeArquivo);
        }
        if(op == 3){
            imprimeTST(Arvore);
        }
        if(op == 4){
            contarPalavrasTST(Arvore);
        }
    }
}
