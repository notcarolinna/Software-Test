#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Unity/src/unity.h"
#include "../src/sort.h"
#include "../Unity/extras/fixture/src/unity_fixture.h"

int sizes[19] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

int vet0[2] = {2,1};
int vet1[3] = {3,2,1};
int vet2[4] = {4,3,2,1};
int vet3[5] = {5,4,3,2,1};
int vet4[6] = {6,5,4,3,2,1};
int vet5[7] = {7,6,5,4,3,2,1};
int vet6[8] = {8,7,6,5,4,3,2,1};
int vet7[9] = {9,8,7,6,5,4,3,2,1};
int vet8[10] = {10,9,8,7,6,5,4,3,2,1};
int vet9[11] = {11,10,9,8,7,6,5,4,3,2,1};
int vet10[12] = {12,11,10,9,8,7,6,5,4,3,2,1}; 
int vet11[13] = {13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet12[14] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet13[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet14[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet15[17] = {17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet16[18] = {18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet17[19] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int vet18[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

void check_sorted(const int vet[], int size);
void teste_foda_pra_caralho(char* complexidade, int tipo);

TEST_GROUP(Sorting);

TEST_SETUP(Sorting)
{
}

TEST_TEAR_DOWN(Sorting)
{
}

// Testa ordenação
TEST(Sorting, TestSorting1){
    teste_foda_pra_caralho("On", COUNTING);
    teste_foda_pra_caralho("On", RADIX);
    teste_foda_pra_caralho("On2", BUBBLE);
    teste_foda_pra_caralho("On2", INSERTION);
    teste_foda_pra_caralho("On2", SELECTION);
    teste_foda_pra_caralho("Onlogn", HEAP);
    teste_foda_pra_caralho("Onlogn", MERGE);
    teste_foda_pra_caralho("Onlogn", QUICK);
}

void teste_foda_pra_caralho(char* complexidade, int tipo) {
    int *vet = malloc(sizes[0] * sizeof(int));
    if (vet != NULL) {
        memcpy(vet, vet0, sizes[0] * sizeof(int));
        sort(vet, sizes[0], complexidade, tipo);
        check_sorted(vet, sizes[0]);
        free(vet);
    }
}

// Testa vetor vazio
TEST(Sorting, TestSorting2)
{
    int vet[] = {}; 
    int size = 0;    

    int status_counting = sort(vet, size, "On", COUNTING);
    int status_radix = sort(vet, size, "On", RADIX);
    int status_bubble = sort(vet, size, "On2", BUBBLE);
    int status_insertion = sort(vet, size, "On2", INSERTION);
    int status_selection = sort(vet, size, "On2", SELECTION);
    int status_heap = sort(vet, size, "Onlogn", HEAP);
    int status_merge = sort(vet, size, "Onlogn", MERGE);
    int status_quick = sort(vet, size, "Onlogn", QUICK);

    TEST_ASSERT_EQUAL(0, status_counting);  
    TEST_ASSERT_EQUAL(0, status_radix);     
    TEST_ASSERT_EQUAL(0, status_bubble);    
    TEST_ASSERT_EQUAL(0, status_insertion);  
    TEST_ASSERT_EQUAL(0, status_selection);  
    TEST_ASSERT_EQUAL(0, status_heap);       
    TEST_ASSERT_EQUAL(0, status_merge);      
    TEST_ASSERT_EQUAL(0, status_quick);     

    TEST_ASSERT_EQUAL(0, size);
}

// Testa em um vetor já ordenado
TEST(Sorting, TestSorting3){
    int size = 3; // Corrigido para o tamanho correto do vetor

    sort(vet1, size, "On", COUNTING);      
    sort(vet2, size, "On", RADIX);       
    sort(vet3, size, "On2", BUBBLE);       
    sort(vet4, size, "On2", INSERTION);    
    sort(vet5, size, "On2", SELECTION);   
    sort(vet6, size, "Onlogn", HEAP);     
    sort(vet7, size, "Onlogn", MERGE);    
    sort(vet8, size, "Onlogn", QUICK);  

    for (int i = 0; i < size; i++) {
        TEST_ASSERT_EQUAL(i + 1, vet1[i]);  
        TEST_ASSERT_EQUAL(i + 1, vet2[i]);
        TEST_ASSERT_EQUAL(i + 1, vet3[i]);
        TEST_ASSERT_EQUAL(i + 1, vet4[i]);
        TEST_ASSERT_EQUAL(i + 1, vet5[i]);
        TEST_ASSERT_EQUAL(i + 1, vet6[i]);
        TEST_ASSERT_EQUAL(i + 1, vet7[i]);
        TEST_ASSERT_EQUAL(i + 1, vet8[i]);
    }
}

// Teste de vetor unitário (Limites entre 2 e 20)
TEST(Sorting, TestSorting4) {
    for (int i = 0; i < 19; i++) {
        int size = sizes[i];
        int *vet = malloc(size * sizeof(int));
        if (vet != NULL) {
            memcpy(vet, vet0, size * sizeof(int)); // Usar o vetor de teste correspondente
            sort(vet, size, "Onlogn", MERGE); // Exemplo com o algoritmo de merge sort
            check_sorted(vet, size); // Verificar se está ordenado
            free(vet);
        }
    }
}

void check_sorted(const int vet[], int size) {
    for (int i = 0; i < size; i++) {
        TEST_ASSERT_EQUAL(i + 1, vet[i]);
    }
}
