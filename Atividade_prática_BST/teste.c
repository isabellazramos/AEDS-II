#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct aluno {
  char *nome; char *matricula;
  int nota;
} aluno;
 
aluno divider(char*);
 
int main(int argc, char** argv) {
  FILE *arq;
  char *token;
  aluno a;
  char line[30];
  arq = fopen("file.txt", "r");
  if (arq == NULL) puts("Error!");
  else {
    while (fscanf(arq, "%s", line) == 1) {
      a = divider(line);
      printf("%s %s %d\n", a.nome, a.matricula, a.nota);
    }
  }
}
 
aluno divider(char *string) {
  char *token; int d = 2;
  aluno a;
  token = strtok(string, "-");
  while (token != NULL) {
    if (d == 2) a.nome = token;
    if (d == 1) a.matricula = token;
    if (d == 0) a.nota = atoi(token);
    token = strtok(NULL, "-");
    d--;
  }
  return a;
}