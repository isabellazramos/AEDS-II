#include "tripulacao.h"
#include <sys/time.h>
#define TAMTABLE 7
#define TAMPESO 200

typedef int TipoPesos[TAMPESO];

typedef struct HASH{
    TipoTripulante Tripulantes[TAMTABLE];
    TipoPesos peso;
}Hash;

void iniciarPesos(int *peso);
void iniciarHash(Hash *hash);
void insereHash(Hash *hash,TipoTripulante tripulante);
void pesquisaHash(Hash hash,TipoTripulante tripulante);
int tranformacaoDeChave(TipoNome* nome, int* peso);
void imprimirHash(Hash hash);
TipoTripulante dividirArquivo(char *string);