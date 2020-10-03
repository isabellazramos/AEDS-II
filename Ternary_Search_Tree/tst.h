#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef int TipoInteiro;
typedef unsigned char TipoChave;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo{
    TipoChave Letra;
    unsigned ehOFimDaString: 1; 
    TipoApontador Esquerda, Igual, Direita; 
}TipoNo;

void inicializaTST(TipoApontador *No);
void insereTST(TipoApontador *No, char *Letra);
void insereTSTAux(TipoApontador *No, char *Letra);
void imprimeTST(TipoApontador No);
void imprimeTSTAux(TipoApontador No, char* buffer, int depth);
int pesquisarTST(TipoApontador *No, char *Palavra);
int abrirArquivo(TipoApontador *Arvore,char *nomeArq);