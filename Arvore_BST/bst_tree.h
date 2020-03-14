//
// Created by isabella on 06/03/2020.
//

#ifndef BST_TREE_BST_TREE_H
#define BST_TREE_BST_TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TipoRegistro{
    int Chave;
}TipoRegistro;
typedef struct TipoNo *TipoApontador;

typedef struct TipoNo{
    TipoRegistro Reg;
    TipoApontador Esq, Dir;
} TipoNo;

void inicializaBST(TipoApontador *Arvore);
void insereBST(TipoRegistro Registro, TipoApontador *Arvore);
void imprimeOrdem(TipoApontador Arvore);
void imprimePreOrdem(TipoApontador Arvore);
void imprimePosOrdem(TipoApontador Arvore);
void pesquisaBST(TipoRegistro aux,TipoApontador Arvore);
int alturaArvoreBST(TipoApontador Arvore);
int maiorChaveBST(TipoApontador Arvore);
int profundidadeBST(TipoApontador Arvore, int chave);
int profundidadeAuxiliarBST(TipoApontador Arvore, int chave, int aux);
int numeroDeNosBST(TipoApontador Arvore);
void removerBSTAuxiliar(TipoApontador aux, TipoApontador *Arvore);
void removerBST(TipoApontador *Arvore, TipoRegistro Registro);

#endif //BST_TREE_BST_TREE_H
