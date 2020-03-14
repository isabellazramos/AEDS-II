//
// Created by isabella on 06/03/2020.
//

#include "bst_tree.h"
void inicializaBST(TipoApontador *Arvore){
    *Arvore = NULL;
}

void insereBST(TipoRegistro Registro, TipoApontador *Arvore){
    if (*Arvore == NULL){
        *Arvore = (TipoApontador)malloc(sizeof(TipoNo));
        (*Arvore)->Reg = Registro;
        (*Arvore)->Dir = NULL;
        (*Arvore)->Esq = NULL;
    }
    else{
        if(Registro.Chave < (*Arvore)->Reg.Chave){
            insereBST(Registro,&(*Arvore)->Esq);
        }
        else{
            insereBST(Registro, &(*Arvore)->Dir);
        }
    }
}

void imprimeOrdem(TipoApontador Arvore) {
    if (Arvore != NULL) {
        imprimeOrdem(Arvore->Esq);
        printf("Chave: %d\n", Arvore->Reg.Chave);
        imprimeOrdem(Arvore->Dir);
    }
}

void imprimePreOrdem(TipoApontador Arvore){
    if(Arvore != NULL){
        printf("Chave: %d\n", Arvore->Reg.Chave);
        imprimePreOrdem(Arvore->Esq);
        imprimePreOrdem(Arvore->Dir);
    }
}

void imprimePosOrdem(TipoApontador Arvore){
    if(Arvore != NULL){
        imprimePosOrdem(Arvore->Esq);
        imprimePosOrdem(Arvore->Dir);
        printf("Chave: %d\n", Arvore->Reg.Chave);
    }
}

void pesquisaBST(TipoRegistro aux, TipoApontador Arvore){
    TipoRegistro aux2;
    if(Arvore != NULL){
        if(Arvore->Reg.Chave ==  aux.Chave){
            printf("Chave encontrada!\n");
        }
        if(Arvore->Reg.Chave > aux.Chave) {
            pesquisaBST(aux, Arvore->Esq);
        }
        if(Arvore->Reg.Chave < aux.Chave){
            pesquisaBST(aux, Arvore->Dir);
        }
    } else{
        printf("Chave não encontrada!\n");
    }
}

int alturaArvoreBST(TipoApontador Arvore){
    if(Arvore == NULL){
        return -1;
    }
    else{
        int he = alturaArvoreBST(Arvore->Esq);
        int hd = alturaArvoreBST(Arvore->Dir);
        if(he < hd) return hd + 1;
        else return he + 1;
    }
}

int numeroDeNosBST(TipoApontador Arvore){
    if(Arvore == NULL){
        return 0;
    }else{
        return 1 + numeroDeNosBST(Arvore->Esq) + numeroDeNosBST(Arvore->Dir);
    }
}

int maiorChaveBST(TipoApontador Arvore){
    if(Arvore->Dir == NULL){
        return (Arvore->Reg.Chave);
    }else{
        maiorChaveBST(Arvore->Dir);
    }
}


int profundidadeBST(TipoApontador Arvore, int chave){
    int aux = 0;
    return  (profundidadeAuxiliarBST(Arvore, chave, aux));

}

int profundidadeAuxiliarBST(TipoApontador Arvore, int chave, int aux){
    if(Arvore != NULL){
        if(Arvore->Reg.Chave ==  chave){
            printf("Chave encontrada!\n");
            return aux;
        }
        else if(Arvore->Reg.Chave !=  chave){
            aux += 1;
            if(Arvore->Reg.Chave > chave) {
                return profundidadeAuxiliarBST(Arvore->Esq, chave, aux);
            }
            if(Arvore->Reg.Chave < chave){
                return profundidadeAuxiliarBST(Arvore->Dir, chave, aux);
            }
        }
    } else{
        printf("Chave não encontrada!\n");
        return 0;
    }
}

void removerBSTAuxiliar(TipoApontador aux, TipoApontador *Arvore){
    if((*Arvore)->Dir != NULL){
        removerBSTAuxiliar(aux,&(*Arvore)->Dir);
        return;
    }
    aux->Reg = (*Arvore)->Reg;
    aux = *Arvore;
    *Arvore = (*Arvore)->Esq;
    free(aux);
}
void removerBST(TipoApontador *Arvore, TipoRegistro Registro){
    TipoApontador Aux;
    if(*Arvore == NULL){
        printf("Erro: Registro não está na árvore.\n");
        return;;
    }
    if(Registro.Chave < (*Arvore)->Reg.Chave){
        removerBST(&(*Arvore)->Esq,Registro);
        return;
    }
    if(Registro.Chave > (*Arvore)->Reg.Chave){
        removerBST(&(*Arvore)->Dir,Registro);
        return;
    }
    if((*Arvore)->Dir == NULL){
        Aux = *Arvore;
        *Arvore = (*Arvore)->Esq;
        free(Aux);
        return;
    }
    if((*Arvore)->Esq != NULL){
        removerBSTAuxiliar(*Arvore,&(*Arvore)->Esq);
        return;
    }
    Aux = *Arvore;
    *Arvore = (*Arvore)->Dir;
    free(Aux);
}