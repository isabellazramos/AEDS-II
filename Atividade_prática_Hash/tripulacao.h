#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMNAME 100

typedef char TipoNome;
typedef int TipoCodigo;

typedef struct TipoTripulante{
    TipoNome nomeTripulante[TAMNAME];
    TipoCodigo codigoTripulante;
}TipoTripulante;