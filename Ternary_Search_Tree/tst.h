#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef unsigned char TipoChave;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo{
    TipoChave Letra;
    unsigned ehOFimDaString: 1; 
    TipoApontador Esquerda, Igual, Direita; 
}TipoNo;

void inicializaTST(TipoApontador *No);
void insereTST(TipoApontador *No, char *Letra);
void imprimeTST(TipoApontador No);
void imprimeTSTAux(TipoApontador No, char* buffer, int depth);