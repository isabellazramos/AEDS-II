# Trabalho prático 01

O trabalho visa a implementar os TADs Árvore TRIE TST e PATRICIA para armazenar palavras de um texto ou dicionário, para fins de comparação em termos do custo computacional das operações de inserção e pesquisa.

## Tarefas

- [x] Criar uma árvore TRIE (TST) e uma árvore PATRICIA para armazenar as palavras de um texto ou dicionário à escolha do grupo. No caso de se usar o texto, recomenda-se transformar as palavras para minúsculas antes da inserção nas árvores. Recomenda-se ainda usar dicionário e/ou texto em inglês para evitar acentuação.

- [x] Para a árvore PATRICIA, adaptar os algoritmos fornecidos em sala de aula para permitir o armazenamento de palavras. A solução mais comum é inserir mais um campo de comparação em cada nó, ou seja, além do campo de índice (que avança x posições na palavra) será necessário também ter um campo com o caracter que está sendo comparado naquela posição para se decidir o caminho a seguir (esquerda ou direita). A decisão de se colocar, no nó interno, o menor ou o maior caracter de comparação e se os iguais ficarão à esquerda ou à direita deste nó, deverá levar em conta o melhor uso de memória e a diferença de tamanho entre as palavras.

- [x] Cada árvore conterá apenas uma ocorrência de cada palavra inserida, não sendo permitida a inserção de palavras iguais nem sendo necessário registrar o número de ocorrências das palavras no texto (quando for o caso).

- [x] A estrutura da árvore TRIE TST está diretamente relacionada às primeiras chaves inseridas. Portanto, para o armazenamento de chaves de um dicionário, os testes devem considerar cenários onde as chaves são inseridas também em ordem aleatória e não apenas em ordem alfabética. Replicar os cenários para PATRICIA, para fins de comparação. 

- [x] Usar cenários que permitam avaliar a escalabilidade (falta de) da árvore PATRICIA para palavras com mesmo radical e que se diferem em um mesmo caracter. Para o caso de se usar o texto como fonte de dados, inserir palavras extras que permitam esse teste já que a probabilidade dessas palavras estarem no texto, desta forma, é baixa. As mesmas inserções devem ser feitas na TRIE TST para fins de comparação.

- [x] Os testes objetivam comparar as estruturas quanto aos seguintes parâmetros e cenários: uso de memória, tempo de execução e número de comparações para as operações de inserção (Palavra JÁ EXISTE ou NÃO) e pesquisa (COM e SEM sucesso).

- [x] Todos os testes devem ser realizados em uma mesma máquina, cuja configuração deve ser informada no relatório.

- [x] Elaborar um relatório sintético, contendo: uma introdução, com o objetivo do trabalho e as principais fontes (referências) dos algoritmos utilizados; uma seção de desenvolvimento, com os detalhes da implementação, os testes realizados e a análise dos resultados; e uma seção de considerações finais.

- [x] Na subseção de implementação, explicar em linhas gerais os algoritmos utilizados e as adaptações realizadas para as operações de inserção e pesquisa, podendo inserir alguns pequenos trechos de código na explicação. Demais detalhes de implementação das estruturas devem ser documentados no próprio código.

- [x] Os testes devem ser apresentados em tabelas e gráficos (quando aplicável), agrupados segundo cada cenário utilizado e que permitam
a comparação entre as estruturas.

- [x] O menu de opções do programa deverá conter as seguintes opções: 1) escolher árvore, 2) inserir palavra, 3) pesquisar palavra, 4)exibir todas as palavras em ordem alfabética e 5) contar palavras. Para as operações de inserção e pesquisa, exibir uma mensagem com o número de comparações realizadas.

## Instalação

Para compilar o programa, é necessário GCC instalado na sua máquina. Para executar, basta digitar no terminal dentro do projeto:

```bash
make all
```

## Contribuidores

Os desenvolvedores do projeto são:

- [Calebe Costa](https://github.com/Inoh-Diskts)
- [Isabella Ramos](https://github.com/isabellazramos)
- [Lucas Barros](https://github.com/mocreviz)
- [Vinicius Julio](https://github.com/VinicioHaner)
