// GRUPO DESALOCADOS
// Calebe Costa - 3478
// Isabella Menezes - 3474
// Lucas Barros - 3511
// Vinicius Julio - 3495

#include "../Header/tst.h"
#include <stdio.h>


void inicializaTST(TipoApontador *No){
    // maneira de iniciar uma árvore
    *No = NULL;
}

void insereTST(TipoApontador *No, char *Letra, int *Comparacoes, int *Memoria){
    /* 
        condição para saber se a palavra está ou não na árvore,
        caso não esteja, entra na função de inserir
    */
    if(pesquisarTST(&(*No),Letra, Comparacoes)){
        (*Comparacoes)++;
        printf("A palavra %s ja esta na arvore.\n",Letra);
        return;
    }else
    {
        (*Comparacoes)++;
        insereTSTAux(&(*No),Letra, Comparacoes, Memoria);
        return;
    }
}

void insereTSTAux(TipoApontador *No, char *Letra, int *Comparacoes, int *Memoria){
    /*
        percorre a árvore comparando cada letra da palavra que vai ser inserida
        com a letra que está dentro de cada nó, até que todas as letras sejam inseridas
        e caso isso aconteça, ehOFimDaString recebe valor 1 (TRUE)
    */
    
    if(!(*No)){
        (*Comparacoes)++;
        *No = (TipoApontador)malloc(sizeof(TipoNo));
        (*Memoria) += sizeof(*No);
        (*No)->Letra = *Letra;
        (*No)->Esquerda = NULL;
        (*No)->Direita = NULL;
        (*No)->Igual = NULL;
        (*No)->ehOFimDaString = 0;
    }

    if ((*Letra) < (*No)->Letra){
        (*Comparacoes)++;
        insereTSTAux(&((*No)->Esquerda), Letra,Comparacoes,Memoria);
    } 
    else if ((*Letra) > (*No)->Letra){
        (*Comparacoes)++;
        insereTSTAux(&((*No)->Direita), Letra,Comparacoes,Memoria);
    } 
    else{
        (*Comparacoes)++;
        if (*(Letra+1)){
            (*Comparacoes)++;
            insereTSTAux(&((*No)->Igual ), Letra+1, Comparacoes,Memoria);
        }
        else {
            (*Comparacoes)++;
            (*No)->ehOFimDaString = 1;
            return;
        }
    } 
             
}

void imprimeTST(TipoApontador No){
    char buffer[MAX]; 
    imprimeTSTAux(No, buffer, 0); 
}

void imprimeTSTAux(TipoApontador No, char* buffer, int depth){
    /*
        percorre a árvore e vai guardando no vetor buffer as palavras, caso seja o 
        fim da palavra na árvore, o que está dentro do buffer é printado
        dependendo do formato da árvore, tenho que aumentar o define MAX que se usa no buffer
    */ 
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

int pesquisarTST(TipoApontador *No, char *Palavra, int *Comparacoes) {
    /*
        percorre a arvore comparando as letras de Palavra com as letras dentro de cada nó, se eu chegar
        no fim de Palavra, quer dizer que a Palavra está na árvore
    */

    if (!*No) {
        (*Comparacoes)++;
        return 0;
    }
  
    if (*Palavra < (*No)->Letra){
        (*Comparacoes)++;
        return pesquisarTST(&(*No)->Esquerda, Palavra,Comparacoes);
    }
  
    else if (*Palavra > (*No)->Letra) {
        (*Comparacoes)++;
        return pesquisarTST(&(*No)->Direita, Palavra,Comparacoes);
    }
  
    else
    {
        (*Comparacoes)++;
        if (*(Palavra+1) == '\0') {
            (*Comparacoes)++;
            return (*No)->ehOFimDaString;
        }
        return pesquisarTST(&(*No)->Igual, Palavra+1, Comparacoes);
    } 
} 

void contarPalavrasTST(TipoApontador No){
    int count = 0;
    count = contarPalavrasTSTAux(No);
    printf("A arvore contem %d palavra(s).\n",count);
}

int contarPalavrasTSTAux(TipoApontador No){
    /*
        percorro a árvore e faço a comparação se é o fim da palavra naquele nó (o que me diz que tem uma
        palavra que foi formada) se for verdade, soma um, e no final da recursão tenho a resposta de quantos 
        ehOFimDaString eu tenho, ou seja, quantas palavras eu tenho na árvore
    */
    if(No == NULL){
        return 0;
    }
    else
    {
       return (No-> ehOFimDaString == 1) + contarPalavrasTSTAux(No->Igual) + contarPalavrasTSTAux(No->Direita) + contarPalavrasTSTAux(No->Esquerda);
    }     
}

int abrirArquivo(TipoApontador *Arvore,char *nomeArq,int *Comparacoes, int *Memoria){
    /*
        função para abrir o arquivo, percorro linha por linha do arquivo e utilizo o strtok 
        para "dividir essas linhas" sendo que o critério usado para dividir é o o espaço contido entre uma palavra e outra
        TOMAR CUIDADO COM O TAMANHO DA LINHA
    */
    FILE *pont_arq;
    char Linha[TAMLINHA];
    const char s[2] = " ";
    char *token;
    char aux[30];

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
                insereTST(&(*Arvore),tranformarPalavra(token), Comparacoes, Memoria);
                token = strtok(NULL, s);
            }
        }
    }
    fclose(pont_arq);
}

char* tranformarPalavra(char *palavra){
    int TamStr = strlen(palavra);
    for(int i=0; i<TamStr; i++)
    {                            
     palavra[i] = tolower(palavra[i]);  
    }
    return palavra;
}