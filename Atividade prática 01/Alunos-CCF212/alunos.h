//
// Created by isabella on 10/03/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ALUNOS_CCF212_ALUNOS_H
#define ALUNOS_CCF212_ALUNOS_H

typedef struct TipoAluno{
    float notaAluno;
    char nomeAluno[20];
    int matriculaAluno;
}TipoAluno;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo{
    TipoAluno alunoTipoNo;
    TipoApontador Esq;
    TipoApontador Dir;
}TipoNo;

void inicializaNotas(TipoApontador *Arvore);
void insereNota(TipoApontador *Arvore,TipoAluno Aluno);
void imprimeNotasDecrescenteAuxiliar(TipoApontador Arvore);
void imprimeNotasDecrescente(TipoApontador Arvore);
int numeroDeAlunos(TipoApontador Arvore);
float menorNota(TipoApontador Arvore);
float maiorNota(TipoApontador Arvore);
void alunosComMedia(TipoApontador Arvore);

#endif //ALUNOS_CCF212_ALUNOS_H
