#include "arvore-sbb.h"

int main() {
    int op;
    TipoNo *Arvore;
    TipoRegistro AuxInsere,AuxRemove,AuxPesquisa;

    while (op != 0)
    {
        printf("\n---------------Menu---------------\n");
        printf("1 - inicializar.\n");
        printf("2 - inserir na árvore.\n");
        printf("3 - retirar da árvore.\n");
        printf("4 - imprime arvore.\n");
        printf("5 - pesquisa na arvore.\n");
        printf("------------------------------------\n");
        printf("PRESSIONE 0 PARA SAIR DO PROGRAMA\n");
        printf("------------------------------------\n");
        printf("Opção:");
        scanf("%d",&op);

        if(op == 1){
            InicializaSBB(&Arvore);
            printf("Árvore inicializada com sucesso!\n");
        }
        if(op == 2){
            printf("Digite o valor da chave que deseja inserir:");
            scanf("%d",&AuxInsere.Chave);
            InsereSBB(AuxInsere,&Arvore);
            printf("Chave inserida com sucesso!\n");
        }
        if(op == 3){
            printf("Digite o valor da chave que deseja remover:");
            scanf("%d",&AuxRemove.Chave);
            RetiraSBB(AuxRemove,&Arvore);
            printf("Chave retirada com sucesso!\n");
        }
        if(op == 4){
            ImprimeSBB(Arvore);
        }

        if(op == 5){
            printf("Digite a chave que deseja pesquisar:");
            scanf("%d",&AuxPesquisa.Chave);
            PesquisaSBB(&Arvore,&AuxPesquisa);
        }

        if(op == 0) break;
    }
    

}
