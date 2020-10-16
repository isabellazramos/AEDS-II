#include "hash.h"

int main(){
    Hash hash;
    TipoTripulante tripulante;

    char archiveName[20];

    printf("Digite o nome do arquivo: ");
    scanf("%s", archiveName);

    FILE *f;
    char line[30];
    f = fopen(archiveName,"r");

    if(f == NULL){
        printf("error\n");
    }else
    {
        iniciarHash(&hash);
        iniciarPesos(hash.peso);
        iniciarPesos(hash.peso);
        while (fscanf(f,"%s",line) == 1)
        {
            tripulante = dividirArquivo(line);
            insereHash(&hash,tripulante);
        }
        
    }
    fclose(f);
    strcpy(tripulante.nomeTripulante,"Regina");
    tripulante.codigoTripulante = 28;
    //insereHash(&hash,tripulante);
    imprimirHash(hash);
    pesquisaHash(hash,tripulante);

}