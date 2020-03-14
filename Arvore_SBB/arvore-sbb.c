//
// Created by isabella on 24/03/2020.
//
#include "arvore-sbb.h"

void InicializaSBB(TipoApontador *Arvore){
    *Arvore = NULL;
}

void EE(TipoApontador *Arvore){ 
    TipoApontador Arvore1;
    Arvore1 = (*Arvore)->Esq; (*Arvore)->Esq = Arvore1->Dir; Arvore1->Dir = *Arvore;
    Arvore1->BitEsq = Vertical; (*Arvore)->BitEsq = Vertical; *Arvore = Arvore1;
}  
void ED(TipoApontador *Arvore){ 
    TipoApontador Arvore1, Arvore2;
    Arvore1 = (*Arvore)->Esq; Arvore2 = Arvore1->Dir; Arvore1->BitDir = Vertical;
    (*Arvore)->BitEsq = Vertical; Arvore1->Dir = Arvore2->Esq; Arvore2->Esq = Arvore1;
    (*Arvore)->Esq = Arvore2->Dir; Arvore2->Dir = *Arvore; *Arvore = Arvore2;
}
void DD(TipoApontador *Arvore){ 
    TipoApontador Arvore1;
    Arvore1 = (*Arvore)->Dir; (*Arvore)->Dir = Arvore1->Esq; Arvore1->Esq = *Arvore;
    Arvore1->BitDir = Vertical; (*Arvore)->BitDir = Vertical; *Arvore = Arvore1;
}
void DE(TipoApontador *Arvore){
    TipoApontador Arvore1, Arvore2;
    Arvore1 = (*Arvore)->Dir; Arvore2 = Arvore1->Esq; Arvore1->BitEsq = Vertical;
    (*Arvore)->BitDir = Vertical; Arvore1->Esq = Arvore2->Dir; Arvore2->Dir = Arvore1;
    (*Arvore)->Dir = Arvore2->Esq; Arvore2->Esq = *Arvore; *Arvore = Arvore2;
}

void InsereSBB(TipoRegistro Chave, TipoApontador *Arvore){
    short Fim;
    TipoInclinacao IAp;
    IInsereSBB(Chave,Arvore,&IAp,&Fim);
}

void IInsereSBB(TipoRegistro Chave,TipoApontador *Arvore, TipoInclinacao *IAp, short *Fim){
    if(*Arvore == NULL){
        *Arvore = (TipoApontador)malloc(sizeof(TipoNo));
        *IAp = Horizontal;
        (*Arvore)->Registro = Chave;
        (*Arvore)->BitEsq = Vertical;
        (*Arvore)->BitDir = Vertical;
        (*Arvore)->Esq = NULL;
        (*Arvore)->Dir = NULL;
        *Fim = FALSE;
        return;
    }
    if(Chave.Chave < (*Arvore)->Registro.Chave){
        IInsereSBB(Chave,&(*Arvore)->Esq,&(*Arvore)->BitEsq,Fim);
        if(*Fim) return;
        if((*Arvore)->BitEsq != Horizontal){
            *Fim = TRUE;
            return;
        }
        if((*Arvore)->Esq->BitEsq == Horizontal){
            EE(Arvore);
            *IAp = Horizontal;
            return;
        }
        if((*Arvore)->Esq->BitDir == Horizontal){
            ED(Arvore);
            *IAp = Horizontal;
        }
        return;
    }
    if(Chave.Chave <= (*Arvore)->Registro.Chave){
        printf("Erro: Chave ja esta na arvore\n");
        *Fim = TRUE;
        return;
    }
    IInsereSBB(Chave,&(*Arvore)->Dir,&(*Arvore)->BitDir,Fim);
    if(*Fim) return;
    if((*Arvore)->BitDir != Horizontal){
        *Fim = TRUE;
        return;
    }
    if((*Arvore)->Dir->BitDir == Horizontal){
        DD(Arvore);
        *IAp = Horizontal;
        return;
    }
    if((*Arvore)->Dir->BitEsq == Horizontal){
        DE(Arvore);
        *IAp = Horizontal;
    }
}

void EsqCurto(TipoApontador *Arvore, short *Fim)
{ /* Folha esquerda retirada => arvore curta na altura esquerda */
  TipoApontador Arvore1;
  if ((*Arvore)->BitEsq == Horizontal) 
  { (*Arvore)->BitEsq = Vertical; *Fim = TRUE; return; }
  if ((*Arvore)->BitDir == Horizontal) 
  { Arvore1 = (*Arvore)->Dir; (*Arvore)->Dir = Arvore1->Esq; Arvore1->Esq = *Arvore; *Arvore = Arvore1;
    if ((*Arvore)->Esq->Dir->BitEsq == Horizontal) 
    { DE(&(*Arvore)->Esq); (*Arvore)->BitEsq = Horizontal;}
    else if ((*Arvore)->Esq->Dir->BitDir == Horizontal) 
         { DD(&(*Arvore)->Esq); (*Arvore)->BitEsq = Horizontal; }
    *Fim = TRUE;
    return;
  }
  (*Arvore)->BitDir = Horizontal;
  if ((*Arvore)->Dir->BitEsq == Horizontal) { DE(Arvore); *Fim = TRUE; return; }
  if ((*Arvore)->Dir->BitDir == Horizontal) {  DD(Arvore); *Fim = TRUE; }
} 

void DirCurto(TipoApontador *Arvore, short *Fim)
{ /* Folha direita retirada => arvore curta na altura direita */
  TipoApontador Arvore1;
  if ((*Arvore)->BitDir == Horizontal)
  { (*Arvore)->BitDir = Vertical; *Fim = TRUE; return; }
  if ((*Arvore)->BitEsq == Horizontal) 
  { Arvore1 = (*Arvore)->Esq; (*Arvore)->Esq = Arvore1->Dir; Arvore1->Dir = *Arvore; *Arvore = Arvore1;
    if ((*Arvore)->Dir->Esq->BitDir == Horizontal) 
    { ED(&(*Arvore)->Dir); (*Arvore)->BitDir = Horizontal; } 
    else if ((*Arvore)->Dir->Esq->BitEsq == Horizontal) 
         { EE(&(*Arvore)->Dir); (*Arvore)->BitDir = Horizontal;}
    *Fim = TRUE;
    return;
  }
  (*Arvore)->BitEsq = Horizontal;
  if ((*Arvore)->Esq->BitDir == Horizontal) { ED(Arvore); *Fim = TRUE; return; }
  if ((*Arvore)->Esq->BitEsq == Horizontal) { EE(Arvore); *Fim = TRUE; }
}  

void Antecessor(TipoApontador q, TipoApontador *r, short *Fim)
{ if ((*r)->Dir != NULL) 
  { Antecessor(q, &(*r)->Dir, Fim);
    if (!*Fim) DirCurto(r, Fim);
    return;
  }
  q->Registro = (*r)->Registro; q = *r; *r = (*r)->Esq; free(q);
  if (*r != NULL) *Fim = TRUE;
} 

void IRetiraSBB(TipoRegistro Chave, TipoApontador *Arvore, short *Fim)
{ TipoNo *Auxiliar;
  if (*Arvore == NULL) 
  { printf("Chave nao esta na arvore\n"); *Fim = TRUE; return; }
  if (Chave.Chave < (*Arvore)->Registro.Chave) 
  { IRetiraSBB(Chave, &(*Arvore)->Esq, Fim);
    if (!*Fim) EsqCurto(Arvore, Fim);
    return;
  }
  if (Chave.Chave > (*Arvore)->Registro.Chave) 
  { IRetiraSBB(Chave, &(*Arvore)->Dir, Fim);
    if (!*Fim) DirCurto(Arvore, Fim);
    return;
  }
  *Fim = FALSE; Auxiliar = *Arvore;
  if (Auxiliar->Dir == NULL) 
  { *Arvore = Auxiliar->Esq;  free(Auxiliar);
    if (*Arvore != NULL) *Fim = TRUE;
    return;
  }
  if (Auxiliar->Esq == NULL) 
  { *Arvore = Auxiliar->Dir; free(Auxiliar);
    if (*Arvore != NULL) *Fim = TRUE;
    return;
  }
  Antecessor(Auxiliar, &Auxiliar->Esq, Fim);
  if (!*Fim) EsqCurto(Arvore, Fim); /* Encontrou chave */
} 

void RetiraSBB(TipoRegistro Chave, TipoApontador *Arvore)
{ short Fim;
  IRetiraSBB(Chave, Arvore, &Fim);
} 

void ImprimeSBB(TipoApontador Arvore){
    if(Arvore != NULL){
        ImprimeSBB(Arvore->Esq);
        printf("%d\n",Arvore->Registro.Chave);
        ImprimeSBB(Arvore->Dir);
    }
}

void PesquisaSBB(TipoApontador *Arvore, TipoRegistro *Chave){
    if(*Arvore == NULL){
        printf("Erro: Registro nao esta presente na arvore!\n");
        return;
    }

    if(Chave->Chave < (*Arvore)->Registro.Chave){
        PesquisaSBB(Chave, &(*Arvore)->Esq);
        return;
    }

    if(Chave->Chave > (*Arvore)->Registro.Chave){
        PesquisaSBB(Chave, &(*Arvore)->Dir);
    } else{
        printf("Valor Encontrado!\n");
        *Chave = (*Arvore)->Registro;
    }
}