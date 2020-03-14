//
// Created by isabella on 24/03/2020.
//
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0

#ifndef ARVORE_SBB_ARVORE_SBB_H
#define ARVORE_SBB_ARVORE_SBB_H

typedef struct TipoRegistro{
    int Chave;
}TipoRegistro;

typedef enum {
    Vertical,Horizontal
}TipoInclinacao;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo{
    TipoRegistro Registro;
    TipoApontador Esq, Dir;
    TipoInclinacao BitEsq,BitDir;
}TipoNo;

void InicializaSBB(TipoApontador *Arvore);
void EE(TipoApontador *Arvore);
void ED(TipoApontador *Arvore);
void DE(TipoApontador *Arvore);
void DD(TipoApontador *Arvore);
void InsereSBB(TipoRegistro Chave, TipoApontador *Arvore);
void IInsereSBB(TipoRegistro Chave,TipoApontador *Arvore, TipoInclinacao *IAp, short *Fim);
void EsqCurto(TipoApontador *Arvore, short *Fim);
void DirCurto(TipoApontador *Arvore, short *Fim);
void Antecessor(TipoApontador q, TipoApontador *r, short *Fim);
void IRetiraSBB(TipoRegistro Chave, TipoApontador *Arvore, short *Fim);
void RetiraSBB(TipoRegistro Chave, TipoApontador *Arvore);
void ImprimeSBB(TipoApontador Arvore);
void PesquisaSBB(TipoApontador *Arvore, TipoRegistro *Chave);

#endif //ARVORE_SBB_ARVORE_SBB_H
