#include "tst.h"


void inicializaTST(TipoApontador *No){
    *No = NULL;
}

void insereTST(TipoApontador *No, char *Letra){
    if(pesquisarTST(&(*No),Letra)){
        printf("A palavra %s já está na árvore.\n",Letra);
        return;
    }else
    {
        insereTSTAux(&(*No),Letra);
        return;
    }
    
}

void insereTSTAux(TipoApontador *No, char *Letra){

    if(!(*No)){
        *No = (TipoApontador)malloc(sizeof(TipoNo));
        (*No)->Letra = *Letra;
        (*No)->Esquerda = NULL;
        (*No)->Direita = NULL;
        (*No)->Igual = NULL;
        (*No)->ehOFimDaString = 0;
    }

    if ((*Letra) < (*No)->Letra){
        insereTSTAux(&((*No)->Esquerda), Letra); 
    } 
    else if ((*Letra) > (*No)->Letra){
        insereTSTAux(&((*No)->Direita), Letra);
    } 
    else
    { 
        if (*(Letra+1)) 
            insereTSTAux(&((*No)->Igual ), Letra+1); 
  
        
        else
            (*No)->ehOFimDaString = 1;
            return; 
    } 
             
}

void imprimeTST(TipoApontador No){
    char buffer[MAX]; 
    imprimeTSTAux(No, buffer, 0); 
}

void imprimeTSTAux(TipoApontador No, char* buffer, int depth) 
{ 
    if (No) 
    { 
        imprimeTSTAux(No->Esquerda, buffer, depth); 
  
        buffer[depth] = No->Letra; 
        if (No->ehOFimDaString) 
        { 
            buffer[depth+1] = '\0'; 
            printf( "%s\n", buffer); 
        } 
   
        imprimeTSTAux(No->Igual, buffer, depth + 1); 
  
        imprimeTSTAux(No->Direita, buffer, depth); 
    } 
} 

int pesquisarTST(TipoApontador *No, char *Palavra) 
{ 
    if (!*No) 
        return 0; 
  
    if (*Palavra < (*No)->Letra) 
        return pesquisarTST(&(*No)->Esquerda, Palavra); 
  
    else if (*Palavra > (*No)->Letra) 
        return pesquisarTST(&(*No)->Direita, Palavra); 
  
    else
    { 
        if (*(Palavra+1) == '\0') 
            return (*No)->ehOFimDaString; 
  
        return pesquisarTST(&(*No)->Igual, Palavra+1); 
    } 
} 

int abrirArquivo(TipoApontador *Arvore,char *nomeArq){
    FILE *pont_arq;
    char Linha[100];
    const char s[2] = " ";
    char *token;
    
    pont_arq = fopen(nomeArq, "r");

    if(pont_arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }

    while (!feof(pont_arq))
    {
        fscanf(pont_arq,"%s",Linha);

        if (Linha){
            token = strtok(Linha, s);
            while(token != NULL) {
                insereTST(&(*Arvore),token);
                
                token = strtok(NULL, s);
            }
        }
    }
    fclose(pont_arq);
}