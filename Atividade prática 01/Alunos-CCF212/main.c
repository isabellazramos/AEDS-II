#include "alunos.h"


int main() {
    TipoNo *Arvore;
    TipoAluno Aux;
    int op = -1;
    /*
    inicializaNotas(&Arvore);
    char nome_arquivo[20];

    printf("Digite o nome do Arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *f;
    char palavra[50];
    f = fopen("arquivo.txt", "r");

    if (f == NULL) {
        printf("Não foi Possivel abrir o Arquivo!\n");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", palavra);
            strcpy(Aux.nomeAluno, palavra);
            printf("%s\n", Aux.nomeAluno);
            fscanf(f, "%s", palavra);
            Aux.matriculaAluno = atoi(palavra);
            printf("%d\n", Aux.matriculaAluno);
            fscanf(f, "%s", palavra);
            Aux.notaAluno = atof(palavra);
            printf("%lf\n", Aux.notaAluno);
            insereNota(&Arvore, Aux);
        }
    }*/
        while (op != 0) {
            printf("***********************************\n");
            printf("*          ALUNOS CCF 212         *\n");
            printf("***********************************\n");
            printf("* 1 - Inicializar Arvore          *\n");
            printf("* 2 - Inserir na Arvore           *\n");
            printf("* 3 - Imprimir Arvore             *\n");
            printf("* 4 - Numero de alunos            *\n");
            printf("* 5 - Menor Nota                  *\n");
            printf("* 6 - Maior Nota                  *\n");
            printf("* 7 - Alunos com média            *\n");
            printf("***********************************\n");
            printf("*PRESSIONE 0 PARA SAIR DO PROGRAMA*\n");
            printf("***********************************\n");

            scanf("%d", &op);

            if (op == 1) {
                inicializaNotas(&Arvore);
                printf("Arvore inicializada!\n");
            }
            if (op == 2) {
                printf("Digite o nome do aluno: ");
                scanf("%s", Aux.nomeAluno);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &Aux.matriculaAluno);
                printf("Digite a nota do aluno: ");
                scanf("%f", &Aux.notaAluno);
                insereNota(&Arvore, Aux);
                printf("Nota inserida com sucesso!\n");
            }
            if (op == 3) {
                imprimeNotasDecrescente(Arvore);
            }
            if (op == 4) {
                printf("O total de alunos registrados eh: %d\n", numeroDeAlunos(Arvore));
            }
            if (op == 5) {
                printf("A menor nota dos alunos eh: %f\n", menorNota(Arvore));
            }
            if (op == 6) {
                printf("A maior nota dos alunos eh: %f\n", maiorNota(Arvore));
            }
            if (op == 7) {
                printf("Alunos que passaram com média:\n");
                alunosComMedia(Arvore);
            }
            if (op == 0) {
                break;
            }
        }
    }
