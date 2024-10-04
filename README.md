
# Teste de Caixa Branca

O objetivo deste trabalho é empregar ferramentas de descrição de testes e cobertura de código em C de forma automatizada, assegurando que 100% das linhas e branchs sejam cobertas. Os algoritmos a serem testados foram desenvolvidos por Danilo Novakovic e estão disponíveis no repositório [Sorting Algorithms in C](https://github.com/DaniloNovakovic/sorting-algorithms-in-c).

## Estrutura Básica

A função `sort` recebe quatro argumentos: um ponteiro para o vetor de inteiros a ser ordenado (que deve conter entre 2 e 20 elementos), um argumento `length` que indica o comprimento do vetor, a complexidade do algoritmo a ser utilizada e, por fim, o algoritmo de ordenação desejado. As opções de algoritmos incluem Counting, Radix, Bubble, Insertion, Selection, Heap, Merge e Quick. A função retorna '0' caso os parâmetros sejam válidos e '1' caso contrário.

## Recursos Utilizados

Um Makefile foi desenvolvido para automatizar a compilação, e a ferramenta de Continuous Integration do GitHub foi utilizada. As ferramentas de análise de cobertura de código incluem `gcov`, `cppcheck`, `valgrind` e sanitizers. O framework Unity foi utilizado como ferramenta de descrição de testes.

## Pré-requisitos

Antes de começar, certifique-se de que as seguintes ferramentas estão instaladas no seu sistema:

- **GCC**: O compilador de C.
- **Gcov**: Para análise de cobertura de código.
- **Cppcheck**: Para análise estática de código.
- **Valgrind**: Para verificação de memória.
- **Sanitizers**: Para detecção de erros em tempo de execução.
- **Unity**: Framework de testes para C.
- **Make**: Para automatização da compilação.

Você pode instalar as ferramentas necessárias usando o seguinte comando:

```bash
sudo apt-get install gcc gcov cppcheck valgrind
```

## Compilação


1. **Abra um terminal** e navegue até o diretório do projeto:

   ```bash
   cd /caminho/para/SoftwareTest
   ```

2. **Execute o comando `make`** para compilar o projeto:

   ```bash
   make all
   ```

   Este comando utiliza o `Makefile` para compilar os arquivos fonte e exibir no terminal os resultados dos testes e o percentual de cobertura.


## Limpeza do Projeto

Para remover os arquivos gerados durante a compilação e os arquivos de cobertura, use o comando:

```bash
make clean
```

## Casos de Teste das Classes de Equivalência

| Número do Teste    | Nome do Teste           | Casos de Teste                                                                                     |
|--------------------|-------------------------|-----------------------------------------------------------------------------------------------------|
| 1                  | TestSortingAscending     | `{1,2,3,4,5,6,7,8,9,10}`, `{1,2,3,4,5,6,7,8,9,10}`                                                  |
| 2                  | TestSortingDescending    | `{10,9,8,7,6,5,4,3,2,1}`, `{1,2,3,4,5,6,7,8,9,10}`                                                  |
| 3                  | TestSortingDuplicates    | `{3,1,2,3,2,1,3,1,2,3,2,1}`, `{1,1,1,1,2,2,2,2,3,3,3,3}`                                            |
| 4                  | TestSortingNegative      | `{3,2,1,0,-1}`, `{-1,0,1,2,3}`                                                                      |
| 5                  | TestSortingMixed         | `{3,-1,2,-3,1,-2,5,0}`, `{-3,-2,-1,0,1,2,3,5}`                                                      |
| 6                  | TestSortingMinSize       | `{2,1}`, `{1,2}`                                                                                     |
| 7                  | TestSortingMaxSize       | `{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}`, `{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}` |
| 8                  | TestSortingInvalidSize   | `{21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}`, `{21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}` (Valor esperado igual porque é inválido) |
| 9                  | TestSortingZeroSize      | `{}`, `{}` (valor esperado igual porque é inválido)                                                 |


## Falhas

Um problema significativo durante o desenvolvimento do algoritmo de teste ocorreu com as funções `counting_sort` e `radix_sort`, devido à maneira como ambas tratam números negativos. Isso resultou em vários erros de *segmentation fault* (core dumped) nos testes que envolviam valores negativos.
