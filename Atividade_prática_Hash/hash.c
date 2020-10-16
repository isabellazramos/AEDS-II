#include "hash.h"

void iniciarPesos(int* peso){
    int i;
    struct timeval semente;
    gettimeofday(&semente,NULL);
    srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));
    for (i = 0; i < TAMPESO; i++)
    {
        peso[i] = 1 + (int) (10000.0 * rand()/(RAND_MAX + 1.0));
    }
    
}

int tranformacaoDeChave(TipoNome* nome, int* peso){
    int i,x = 0;
    for(i=0; i<= strlen(nome);i++){
        x += (nome[i] * peso[i]);
    }
    return x;
}

void iniciarHash(Hash *hash){
    for (int i = 0; i < TAMTABLE; i++)
    {
        strcpy(hash->Tripulantes[i].nomeTripulante,"\0");
        hash->Tripulantes[i].codigoTripulante = 0;
    }
    
}

void pesquisaHash(Hash hash,TipoTripulante tripulante){
    int transf,resulMod;
    transf = tranformacaoDeChave(tripulante.nomeTripulante,hash.peso);
    for (int i = 0; i < TAMTABLE; i++)
    {
        resulMod = (transf + i) % TAMTABLE;
        if(strcmp(hash.Tripulantes[resulMod].nomeTripulante,tripulante.nomeTripulante) == 0){
            printf("O tripulante está no voo.\n");
            printf("Nome: %s\n",tripulante.nomeTripulante);
            printf("Codigo: %d\n",tripulante.codigoTripulante);
            return;
        }       
    }
    printf("O tripulante não está no voo. \n");
}

void insereHash(Hash *hash,TipoTripulante tripulante){
    int i, transf,resulMod;

    transf = tranformacaoDeChave(tripulante.nomeTripulante,hash->peso);

    for (int i = 0; i < TAMTABLE; i++)
    {
       resulMod = (transf + i) % TAMTABLE;
       if(hash->Tripulantes[resulMod].codigoTripulante == 0){
           hash->Tripulantes[resulMod] = tripulante;
           return;
       }
    }
    if(resulMod == TAMTABLE){
        printf("A tabela está cheia.\n");
    }
}

void imprimirHash(Hash hash){
    printf("Tripulação no voo:\n");
    for (int i = 0; i < TAMTABLE; i++)
    {
        if(hash.Tripulantes[i].codigoTripulante != 0){
            printf("Nome: %s\n",hash.Tripulantes[i].nomeTripulante);
            printf("Codigo: %d\n",hash.Tripulantes[i].codigoTripulante);
            printf("---------------------------------------\n");
        }
    }
    
}

TipoTripulante dividirArquivo(char *string){
    char *token; int d = 1;
    TipoTripulante std;
    token = strtok(string, "-");
    while(token != NULL){
        if(d == 1){
            strcpy(std.nomeTripulante,token);
        }
        if(d == 0){
            std.codigoTripulante = atoi(token);
        }
        token = strtok(NULL,"-");
        d--;
    }
    return std;
}