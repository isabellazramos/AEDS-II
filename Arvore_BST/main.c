#include "bst_tree.h"

int main() {
    TipoNo *Arvore;
    TipoRegistro No,Aux;
    int op;
    while (op != 0){
        printf("----------------------------------\n");
        printf("        MENU - BST       \n");
        printf("1 - Inicializar Arvore. \n");
        printf("2 - Inserir na Arvore. \n");
        printf("3 - Imprimir Arvore - Ordem.\n");
        printf("4 - Imprimir Arvore - Pre Ordem.\n");
        printf("5 - Imprimir Arvore - Pos Ordem.\n");
        printf("6 - Pesquisar na Arvore.\n");
        printf("7 - Achar altura da Arvore.\n");
        printf("8 - Numero de nós\n");
        printf("9 - Maior chave. \n");
        printf("10 - Profundidade chave específica. \n");
        printf("11 - Remover elemento da arvore\n");
        printf("----------------------------------\n");
        printf("PRESSIONE 0 PARA SAIR DO PROGRAMA\n");
        printf("----------------------------------\n");

        scanf("%d",&op);

        if(op == 1){
            inicializaBST(&Arvore);
            printf("Arvore inicializada!\n");
        }
        if(op == 2 ){
            printf("Qual valor deseja inserir na arvore? ");
            scanf("%d",&No.Chave);
            insereBST(No,&Arvore);
        }
        if(op == 3){
            if(Arvore == NULL){
                printf("A arvore eh vazia!\n");
            } else imprimeOrdem(Arvore);
        }
        if(op == 4){
            if(Arvore == NULL){
                printf("A arvore eh vazia!\n");
            } else imprimePreOrdem(Arvore);
        }
        if(op == 5){
            if(Arvore == NULL){
                printf("A arvore eh vazia!\n");
            } else imprimePosOrdem(Arvore);
        }
        if(op == 6){
            printf("Qual chave deseja pesquisar? ");
            scanf("%d",&Aux.Chave);
            pesquisaBST(Aux,Arvore);
        }
        if(op == 7){
            printf("A altura da Arvore eh: %d.\n", alturaArvoreBST(Arvore));
        }
        if(op == 8){
            printf("%d\n", numeroDeNosBST(Arvore));
        }
        if(op == 9){
            if(Arvore == NULL){
                printf("Não há chaves na árvore!");
            }else {
                printf("A maior chave na arvore eh: %d\n", maiorChaveBST(Arvore));
            }
        }
        if(op == 10){
            printf("Digite o valor que deseja saber a profundidadeBST:\n");
            scanf("%d",&Aux.Chave);
            printf("A profundidade desse no eh: %d\n", profundidadeBST(Arvore, Aux.Chave));
        }
        if(op == 11){
            printf("Digite qual elemento deseja retirar da arvore?");
            scanf("%d",&No.Chave);
            removerBST(&Arvore,No);

        }
        if(op == 0){
            printf("Bye! (ಥ﹏ಥ)");
            break ;
        }
    }
}