// GRUPO DESALOCADOS
// Calebe Costa - 3478
// Isabella Menezes - 3474
// Lucas Barros - 3511
// Vinicius Julio - 3495

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Patricia.h"

char Bit(unsigned char i, char k[]){  //Essa funcao retorna o caractere na posicao i de um vetor k[]
    return (k[i]);
};

short NoEExterno(TipoPatNo *no){      //Essa funcao verifica se o no e externo
    return (no->notipo == externo);
};

TipoPatNo *CriaNoInt(int i, char c, TipoPatNo **esq, TipoPatNo **dir, int *Memoria){ //cria no interno,
    TipoPatNo *no;
    no = malloc(sizeof(TipoPatNo));
    (*Memoria) += sizeof(*no); //contador da quantidade de memoria utilizada
    no->notipo = interno;
    no->PatNo.NoInterno.esquerda = *esq;
    no->PatNo.NoInterno.direita = *dir;
    no->PatNo.NoInterno.indice = i;
    no->PatNo.NoInterno.compara = c;
    return no;
};

TipoPatNo *CriaNoExt(char *ch, int *Memoria){  //cria n� externo
    TipoPatNo *no;
    no = malloc(sizeof(TipoPatNo));
    (*Memoria) += sizeof(*no);
    no->notipo = externo;
    no->PatNo.chave = malloc(30*sizeof(char));
    (*Memoria) += sizeof(*no);
    strcpy(no->PatNo.chave, ch);
    //no->conta = 1;
    return no;
};

void BuscaPat(char k[], TipoPatNo *no, int *Comparacoes){ //fun��o de pesquisa
    if (NoEExterno(no)){                                                                            //primeiramente verifica se o n� atual � Externo
        (*Comparacoes)++;
        if(strcmp(k,no->PatNo.chave) == 0){
            (*Comparacoes)++;
            printf("Elemento encontrado: %s\n", no->PatNo.chave);    //depois, compara a string sendo pesquisada com a chave do n� atual
        }
        else{
            (*Comparacoes)++;
            printf("Elemento %s nao encontrado\n", k);
        }
        return;
    }
    if (Bit(no->PatNo.NoInterno.indice, k) < no->PatNo.NoInterno.compara){
        (*Comparacoes)++;
        BuscaPat(k, no->PatNo.NoInterno.esquerda, Comparacoes);  //se o n� n�o for externo, ele faz as compara��es para ver se ele deve chamar a fun��o recursivamente � esquerda ou � direita
    }
    else{
        (*Comparacoes)++;
        BuscaPat(k, no->PatNo.NoInterno.direita, Comparacoes);
    }
};

TipoPatNo *InsereEntre (char k[], char compara, TipoPatNo **no, int i, int *Comparacoes, int *Memoria){ //Essa � a fun��o de inser��o recursiva
    TipoPatNo *Pno;
    if (NoEExterno(*no)){
        (*Comparacoes)++;
        //puts("condicao 1");
        Pno = CriaNoExt(k, Memoria);
        if (Bit(i, k) > Bit (i, (*no)->PatNo.chave)){
            (*Comparacoes)++;
            return CriaNoInt(i, k[i], no, &Pno, Memoria);
        }else{
            (*Comparacoes)++;
            return CriaNoInt(i, (*no)->PatNo.chave[i], &Pno, no, Memoria);
        }
    }

    else if (i == (*no)->PatNo.NoInterno.indice){
        (*Comparacoes)++;
        //puts("condicao 2");
        Pno = CriaNoExt(k, Memoria);
        if (Bit(i, k) > (*no)->PatNo.NoInterno.compara) {
            (*Comparacoes)++;
            return CriaNoInt(i, k[i], no, &Pno, Memoria);
        }else{
            (*Comparacoes)++;
            (*no)->PatNo.NoInterno.esquerda = InsereEntre(k, compara, &(*no)->PatNo.NoInterno.esquerda, i, Comparacoes, Memoria);
            return (*no);
        }
    }

    else if (i < (*no)->PatNo.NoInterno.indice){
        (*Comparacoes)++;
        //puts("condicao 3");
        Pno = CriaNoExt(k, Memoria);
        if (Bit(i, k) > compara){
            (*Comparacoes)++;
            return CriaNoInt(i, k[i], no, &Pno, Memoria);
        }else{
            (*Comparacoes)++;
            return CriaNoInt(i, compara, &Pno, no, Memoria);
        }
    }

    else {
        //puts("condicao 4");
        (*Comparacoes)++;
        if (Bit((*no)->PatNo.NoInterno.indice, k) == (*no)->PatNo.NoInterno.compara){
            (*Comparacoes)++;
            (*no)->PatNo.NoInterno.direita = InsereEntre(k, compara, &(*no)->PatNo.NoInterno.direita, i, Comparacoes, Memoria);
        }else{
            (*Comparacoes)++;
            (*no)->PatNo.NoInterno.esquerda = InsereEntre(k, compara, &(*no)->PatNo.NoInterno.esquerda, i, Comparacoes, Memoria);
        }
        return (*no);
    }
};

TipoPatNo *Insere(char k[], TipoPatNo **no, int *Comparacoes, int *Memoria){ //Essa e a funcao de insercao principal
    TipoPatNo *Pno;
    int i;
    if (*no == NULL){
        (*Comparacoes)++;
        return CriaNoExt(k, Memoria);    //Se a arvore ainda estiver vazia, a funcao cria um no externo com a chave k e retorna esse no
    }else{
        Pno = *no;
        (*Comparacoes)++;
        while (!NoEExterno(Pno)){                                                                                        //caso contrario, ele ira percorrer a arvore ate achar um no externo
            if (Bit(Pno->PatNo.NoInterno.indice, k) == Pno->PatNo.NoInterno.compara){
                (*Comparacoes)++;
                Pno = Pno->PatNo.NoInterno.direita; //se o caracter na posicao "indice" da string "k" for igual ao char "compara", a funcao precorre a arvore pela direita
            }else{
                (*Comparacoes)++;
                Pno = Pno->PatNo.NoInterno.esquerda;
            } //caso contrario percorre a arvore pela esquerda
        }
        i=0;
        while (Bit((int)i, k) == Bit((int)i, Pno->PatNo.chave) && i < strlen(k)) i++;  //essa linha compara caractere por caractere de "k" e "chave" e continua incrementando o "i" ate encontrar um caractere diferente
        if (strcmp(k, Pno->PatNo.chave) == 0){
            (*Comparacoes)++;
            //essa linha compara k e chave para ver se sao iguais, e se forem, retorna uma mensagem de erro
            printf("A palavra %s ja esta na arvore.\n\n", k);
            //p->conta ++;
            return (*no);
        }else{ (*Comparacoes)++;
        return (InsereEntre(k, Pno->PatNo.chave[i], no, i, Comparacoes, Memoria));}                     //se for confirmado que as strings sao diferentes, ele chama o InsereEntre passando a chave "k", o indice "i" encontrado acima,
    }                                                                                  //o i-esimo caractere da chave do no externo encontrado acima, e o no original que foi passado como parametro da funcao Insere
};


//a funcao abaixo conta quantas palavras foram inseridas
int ContaPalavras(TipoPatNo *no){         //bom, a logica e bem simples, se o no for externo ele retorna 1
    if (no->notipo == externo) return 1;  //se for interno, ele chama recursivamente pra direita e a esquerda e retorna a soma de ambos
    else return ContaPalavras(no->PatNo.NoInterno.esquerda) + ContaPalavras(no->PatNo.NoInterno.direita);
};
//OBS: a funcao nao trata nos nulos porque os nos nunca vao ser nulos. Um no interno sempre tera dois filhos nao-nulos, e um no externo nao tem filhos


//a funcao abaixo imprime cada palavra inserida na PATRICIA, em ordem alfabetica
void ImprimePalavras(TipoPatNo *no){
    if (no->notipo == externo) printf("%s\n",no->PatNo.chave); //se o no for externo, imprime a chave dele
    else{                                                     //e se nao, chama recursivamente para os filhos a esquerda e a direita
        ImprimePalavras(no->PatNo.NoInterno.esquerda);
        ImprimePalavras(no->PatNo.NoInterno.direita);
    }
}
