
# Teste de Caixa Branca

O objetivo deste trabalho é empregar ferramentas de descrição de testes e cobertura de código em C de forma automatizada, assegurando que 100% das linhas e ramificações sejam cobertas. Os algoritmos a serem testados foram desenvolvidos por Danilo Novakovic e estão disponíveis no repositório [Sorting Algorithms in C](https://github.com/DaniloNovakovic/sorting-algorithms-in-c).

## Estrutura Básica

A função `sort` recebe quatro argumentos: um ponteiro para o vetor de inteiros a ser ordenado (que deve conter entre 2 e 20 elementos), um argumento `length` que indica o comprimento do vetor, a complexidade do algoritmo a ser utilizada e, por fim, o algoritmo de ordenação desejado. As opções de algoritmos incluem Counting, Radix, Bubble, Insertion, Selection, Heap, Merge e Quick. A função retorna '0' caso os parâmetros sejam válidos e '1' caso contrário.

## Recursos Utilizados

Um Makefile foi desenvolvido para automatizar a compilação, e a ferramenta de Continuous Integration do GitHub foi utilizada. As ferramentas de análise de cobertura de código incluem `gcov`, `cppcheck`, `valgrind` e sanitizers. O framework Unity foi utilizado como ferramenta de descrição de testes, juntamente com `gtest`, `cpptest` e `catch`.

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

   Este comando utiliza o `Makefile` para compilar os arquivos fonte e criar o executável `identifier`.

## Execução dos Testes

Após a compilação, você pode executar o programa para rodar os testes:

```bash
./identifier
```

Os resultados dos testes serão exibidos no terminal.

## Análise de Cobertura de Código

Para gerar a análise de cobertura de código, você pode usar o comando `gcov`. Siga estes passos:

1. Execute o programa para gerar os arquivos de cobertura:

   ```bash
   ./identifier
   ```

2. Use `gcov` para analisar um arquivo específico:

   ```bash
   gcov src/bubble_sort.c
   ```

   Isso criará um arquivo `bubble_sort.c.gcov` que contém informações sobre a cobertura do código.

## Limpeza do Projeto

Para remover os arquivos gerados durante a compilação e os arquivos de cobertura, use o comando:

```bash
make clean
```
