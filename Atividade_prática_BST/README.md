# Armazenar notas implementando árvore binária de pesquisa

**Descrição da atividade:** Utilizar o TAD BST Árvore Binária de Pesquisa para organizar as notas dos alunos de CCF212 para o Fórum Temático (10 pts). Cada nó da árvore deverá armazenar a nota do aluno, assim como o nome e a matrícula. Os nós deverão ser inseridos, a partir do valor de cada nota. Assim, a primeira nota inserida corresponderá à raiz da árvore. Os dados das notas dos alunos deverão ser lidos a partir de um arquivo-texto, em que cada linha do arquivo deverá conter os dados, da seguinte forma: nome – matrícula – grupo - nota. As notas deverão ser representadas como números reais. No arquivo de entrada, os dados deverão estar ordenados alfabeticamente, pelos nomes dos alunos. Como a inserção é feita pela nota, o valor da nota do primeiro aluno vai influenciar no formato da árvore BST resultante.


## Implementações feitas

 - Inserção de alunos 
 - Print dos alunos em ordem decrescente de nota
 - Contagem de número de estudantes
 - Identificação da nota mais baixa
 - Identificação da nota mias alta
 - Grupos com maiores notas
 - Alunos com média
 - Leitura por arquivo

## Uso

Para compilar o código você precisará ter um compilador de C no seu computador.

Para compilar basta rodar o seguinte comando dentro da pasta baixada
```bash
    make all
```
Logo depois você só ira precisar de fornecer o nome do arquivo de extensão **.txt** quando o programa for executado.

O arquivo deverá ter  a seguinte formatação
```
    Altamiro-EF03477-Grupo2-60
    Ana-EF03477-Grupo4-40
    Isabella-EF09999-Grupo1-80
    João-EF09999-Grupo3-70
    Marcos-EF03476-Grupo5-30    
    Maria-EF03474-Grupo3-20
    Paulo-EF03470-Grupo7-50
```

Sendo NomeDoAluno-Matricula-NomeDoGrupo-Nota , separados por um '-'.

## Implementações a ser feitas

 - [ ] Criar um menu interativo.
 - [ ] Mudar o total e a média da pontuação para 10 pontos.
 - [ ] Criar um arquivo com nomes em ordem alfabética

## Licença
[MIT](https://choosealicense.com/licenses/mit/)
