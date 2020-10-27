// GRUPO DESALOCADOS
// Calebe Costa - 3478
// Isabella Menezes - 3474
// Lucas Barros - 3511
// Vinicius Julio - 3495

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TST/Header/tst.h"
#include "PATRICIA/TAD_Patricia.h"

int main() {
    clock_t tempoInicio, tempoFim;
    int opcheck;
    int checktree;
    int Comparacoes;
    int Memoria;
    FILE *pont_arq;

    TipoApontador Arvore;
    TipoChave Palavra[50];
    int op = -1;

    char aux[20];

    char nomeArquivo[20];

    inicializaTST(&Arvore);
    char key[30];
    TipoPatNo *pat = NULL;
    tempoInicio = 0;
    tempoFim = 0;
    do {
        printf("|***************************************|\n");
        printf("|                 Menu                  |\n");
        printf("| Escolher arvore                       |\n");
        printf("| 1 - TRIE TST                          |\n");
        printf("| 2 - PATRICIA                          |\n");
        printf("| 0 - Encerrar                          |\n");
        printf("|***************************************|\n");
        fflush(stdin);
        scanf("%d", &checktree);
        if (checktree == 1) {
            inicializaTST(&Arvore);
            int opcheck;
            do {
                printf("|***************************************|\n");
                printf("|               Menu TST                |\n");
                printf("|                                       |\n");
                printf("| Opcoes                                |\n");
                printf("| 1 - Ler arquivo e inserir na arvore   |\n");
                printf("| 2 - Inserir palavra                   |\n");
                printf("| 3 - Pesquisar palavra                 |\n");
                printf("| 4 - Exibir arvore                     |\n");
                printf("| 5 - Quantidade de palavras            |\n");
                printf("| 0 - Voltar                            |\n");
                printf("|***************************************|\n");
                fflush(stdin);
                scanf("%d", &opcheck);
                if (opcheck == 1) { //operações na arvore TST
                    Comparacoes = 0;
                    Memoria = 0;
                    printf("Digite o nome do arquivo:\n");
                    scanf("%s", nomeArquivo);
                    tempoInicio = clock();
                    abrirArquivo(&Arvore, nomeArquivo, &Comparacoes, &Memoria);
                    tempoFim = clock();
                    printf("Numero de Comparacoes: %d\nTempo de execucao: %lf ms\nMemoria alocada: %d bytes\n\n", Comparacoes,
                           ((double)(tempoFim - tempoInicio) * 1000)/(CLOCKS_PER_SEC), Memoria);
                } else if (opcheck == 2) {
                    Comparacoes = 0;
                    Memoria = 0;
                    printf("Digite a palavra a ser inserida:\n");
                    scanf("%s", aux);
                    tempoInicio = clock();
                    insereTST(&Arvore, tranformarPalavra(aux), &Comparacoes, &Memoria);
                    tempoFim = clock();
                    printf("Numero de Comparacoes: %d\nTempo de execucao: %lf ms\nMemoria alocada: %d bytes\n\n", Comparacoes,
                           ((double)(tempoFim - tempoInicio) * 1000)/(CLOCKS_PER_SEC), Memoria);
                } else if (opcheck == 3) {
                    Comparacoes = 0;
                    printf("Digite a palavra a ser pesquisada:\n");
                    scanf("%s", Palavra);
                    tempoInicio = clock();
                    if(pesquisarTST(&Arvore, Palavra, &Comparacoes)){
                        Comparacoes++;
                        printf("A palavra %s esta na arvore.\n",Palavra);
                    }else{
                        Comparacoes++;
                        printf("Palavra nao encontrada\n");
                    }
                    tempoFim = clock();
                    printf("Numero de Comparacoes: %d\nTempo de execucao: %lf ms\n\n", Comparacoes,
                           ((double)(tempoFim - tempoInicio) * 1000)/(CLOCKS_PER_SEC));
                } else if (opcheck == 4) {
                    imprimeTST(Arvore);
                    printf("\n\n");
                } else if (opcheck == 5) {
                    contarPalavrasTST(Arvore);
                }
            } while (opcheck != 0);
        } else if (checktree == 2) {
            int opcheck;
            do {
                printf("|***************************************|\n");
                printf("|             Menu PATRICIA             |\n");
                printf("|                                       |\n");
                printf("| Opcoes                                |\n");
                printf("| 1 - Ler arquivo e inserir na arvore   |\n");
                printf("| 2 - Inserir palavra                   |\n");
                printf("| 3 - Pesquisar palavra                 |\n");
                printf("| 4 - Exibir arvore                     |\n");
                printf("| 5 - Quantidade de palavras            |\n");
                printf("| 0 - Voltar                            |\n");
                printf("|***************************************|\n");
                fflush(stdin);
                scanf("%d", &opcheck);
                if (opcheck == 1) { //operações na arvore PATRICIA
                    Comparacoes = 0;
                    Memoria = 0;
                    printf("Digite o nome do arquivo:\n");
                    scanf("%s", nomeArquivo);
                    pont_arq = fopen(nomeArquivo,"r+");
                    tempoInicio = clock();
                    while (fscanf(pont_arq, "%s", key) == 1) {
                        pat = Insere(key, &pat, &Comparacoes, &Memoria);
                    }
                    tempoFim = clock();
                    printf("Numero de Comparacoes: %d\nTempo de execucao: %lf ms\nMemoria alocada: %d bytes\n\n", Comparacoes,
                           ((double)(tempoFim - tempoInicio) * 1000)/(CLOCKS_PER_SEC), Memoria);
                } else if (opcheck == 2) {
                    Comparacoes = 0;
                    Memoria = 0;
                    printf("Digite a palavra a ser inserida:\n");
                    scanf("%s", aux);
                    tempoInicio = clock();
                    pat = Insere(aux, &pat, &Comparacoes, &Memoria);
                    tempoFim = clock();
                    printf("\nNumero de Comparacoes: %d\nTempo de execucao: %lf ms\nMemoria alocada: %d bytes\n\n", Comparacoes,
                           ((double)(tempoFim - tempoInicio) * 1000)/(CLOCKS_PER_SEC), Memoria);
                } else if (opcheck == 3) {
                    Comparacoes = 0;
                    printf("Digite a palavra a ser pesquisada:\n");
                    scanf("%s", key);
                    tempoInicio = clock();
                    BuscaPat(key, pat, &Comparacoes);
                    tempoFim = clock();
                    printf("Numero de Comparacoes: %d\nTempo de execucao: %lf ms\n\n", Comparacoes,
                           ((double)(tempoFim - tempoInicio) * 1000)/(CLOCKS_PER_SEC));
                } else if (opcheck == 4) {
                    ImprimePalavras(pat);
                    printf("\n\n");
                } else if (opcheck == 5) {
                    int pal = ContaPalavras(pat);
                    printf("A arvore contem %d palavras\n\n", pal);
                }
            } while (opcheck != 0);

        }

    }while (checktree!=0);
}

