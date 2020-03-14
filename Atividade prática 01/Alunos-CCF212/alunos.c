//
// Created by isabella on 10/03/2020.
//
#include "alunos.h"

void inicializaNotas(TipoApontador *Arvore){
    *Arvore = NULL;
}

void insereNota(TipoApontador *Arvore,TipoAluno Aluno){
    if(*Arvore == NULL){
        *Arvore = (TipoApontador)malloc(sizeof(TipoNo));
        (*Arvore)->Dir = NULL;
        (*Arvore)->Esq=NULL;
        strcpy((*Arvore)->alunoTipoNo.nomeAluno,Aluno.nomeAluno);
        (*Arvore)->alunoTipoNo.matriculaAluno = Aluno.matriculaAluno;
        (*Arvore)->alunoTipoNo.notaAluno = Aluno.notaAluno;
    }else{
        if(Aluno.notaAluno < (*Arvore)->alunoTipoNo.notaAluno){
            insereNota(&(*Arvore)->Esq,Aluno);
        }
        if(Aluno.notaAluno > (*Arvore)->alunoTipoNo.notaAluno){
            insereNota(&(*Arvore)->Dir,Aluno);
        }
    }
}

void imprimeNotasDecrescente(TipoApontador Arvore){
    if(Arvore == NULL){
        printf("Arvore vazia!\n");
    } else{
        imprimeNotasDecrescenteAuxiliar(Arvore);
    }

}

void imprimeNotasDecrescenteAuxiliar(TipoApontador Arvore){
    if(Arvore != NULL){
        imprimeNotasDecrescenteAuxiliar(Arvore->Dir);
        printf("------------------------------\n");
        printf("NOME: %s\n",Arvore->alunoTipoNo.nomeAluno);
        printf("MATRICULA: %d\n",Arvore->alunoTipoNo.matriculaAluno);
        printf("NOTA: %f\n", Arvore->alunoTipoNo.notaAluno);
        printf("------------------------------\n");
        imprimeNotasDecrescenteAuxiliar(Arvore->Esq);
    }
}

int numeroDeAlunos(TipoApontador Arvore){
    if(Arvore == NULL){
        return 0;
    }else{
        return 1 + numeroDeAlunos(Arvore->Esq) + numeroDeAlunos(Arvore->Dir);
    }
}

float menorNota(TipoApontador Arvore){
    if(Arvore != NULL){
        if(Arvore->Esq == NULL){
            printf("------------------------------\n");
            printf("NOME: %s\n",Arvore->alunoTipoNo.nomeAluno);
            printf("MATRICULA: %d\n",Arvore->alunoTipoNo.matriculaAluno);
            printf("NOTA: %f\n", Arvore->alunoTipoNo.notaAluno);
            printf("------------------------------\n");
            return Arvore->alunoTipoNo.notaAluno;
        }else{
            menorNota(Arvore->Esq);
        }
    }
}

float maiorNota(TipoApontador Arvore){
    if(Arvore != NULL){
        if(Arvore->Dir == NULL){
            printf("------------------------------\n");
            printf("NOME: %s\n",Arvore->alunoTipoNo.nomeAluno);
            printf("MATRICULA: %d\n",Arvore->alunoTipoNo.matriculaAluno);
            printf("NOTA: %f\n", Arvore->alunoTipoNo.notaAluno);
            printf("------------------------------\n");
            return Arvore->alunoTipoNo.notaAluno;
        }else{
            maiorNota(Arvore->Dir);
        }
    }
}
void alunosComMedia(TipoApontador Arvore){
    if(Arvore != NULL){
        if(Arvore->alunoTipoNo.notaAluno >= 6){
            printf("------------------------------\n");
            printf("NOME: %s\n",Arvore->alunoTipoNo.nomeAluno);
            printf("MATRICULA: %d\n",Arvore->alunoTipoNo.matriculaAluno);
            printf("NOTA: %f\n", Arvore->alunoTipoNo.notaAluno);
            printf("------------------------------\n");
        }
        alunosComMedia(Arvore->Dir);
        alunosComMedia(Arvore->Esq);
    }
}