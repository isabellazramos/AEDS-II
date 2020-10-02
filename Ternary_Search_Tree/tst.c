#include "tst.h"


void inicializaTST(TipoApontador *No){
    *No = NULL;
}

void insereTST(TipoApontador *No, char *Letra){
    
    if(!(*No)){
        *No = (TipoApontador)malloc(sizeof(TipoNo));
        (*No)->Letra = *Letra;
        (*No)->Esquerda = NULL;
        (*No)->Direita = NULL;
        (*No)->Igual = NULL;
        (*No)->ehOFimDaString = 0;
    }

    if ((*Letra) < (*No)->Letra){
        insereTST(&((*No)->Esquerda), Letra); 
    } 
    else if ((*Letra) > (*No)->Letra){
        insereTST(&((*No)->Direita), Letra);
    } 
    else
    { 
        if (*(Letra+1)) 
            insereTST(&((*No)->Igual ), Letra+1); 
  
        
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