// GRUPO DESALOCADOS
// Calebe Costa - 3478
// Isabella Menezes - 3474
// Lucas Barros - 3511
// Vinicius Julio - 3495

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
#define TAMLINHA 100

typedef int TipoInteiro;
typedef unsigned char TipoChave;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo{
    TipoChave Letra;
    unsigned ehOFimDaString: 1; 
    TipoApontador Esquerda, Igual, Direita; 
}TipoNo;

void inicializaTST(TipoApontador *No);
void insereTST(TipoApontador *No, char *Letra, int *Comparacoes, int *Memoria);
void insereTSTAux(TipoApontador *No, char *Letra, int *Comparacoes, int *Memoria);
void imprimeTST(TipoApontador No);
void imprimeTSTAux(TipoApontador No, char* buffer, int depth);
int pesquisarTST(TipoApontador *No, char *Palavra, int *Comparacoes);
int abrirArquivo(TipoApontador *Arvore,char *nomeArq, int *Comparacoes, int *Memoria);
void contarPalavrasTST(TipoApontador No);
int contarPalavrasTSTAux(TipoApontador No);
char* tranformarPalavra(char *palavra);

