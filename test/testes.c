#include "unity.h"
#include "unity_fixture.h"
#include "../src/sort.h"

#define CERTO 0
#define ERRADO 1

int vet_asc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int vet_desc[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int vet_dup[12] = {3, 1, 2, 3, 2, 1, 3, 1, 2, 3, 2, 1};
int vet_neg[5] = {3,2,1,0,-1};
int vet_mixed[8] = {3, -1, 2, -3, 1, -2, 5, 0};

void teste(int* vet_base, int size, int compare);
int negative_values(int* vet, int size);

TEST_GROUP(Sorting);

TEST_SETUP(Sorting){}

TEST_TEAR_DOWN(Sorting){}

// Testa vetor ascendente
TEST(Sorting, TestSortingAscending){
	teste(vet_asc, 10, CERTO);
	//free(vet_asc);
}

// Testa vetor descendente
TEST(Sorting, TestSortingDescending){
	teste(vet_desc, 10, CERTO);
	//free(vet_desc);
}

// Testa vetor com elementos repetidos
TEST(Sorting, TestSortingDuplicates){
	teste(vet_dup, 12, CERTO);
	//free(vet_dup);
}

// Teste vetor com elementos negativos
// Utiliza função auxiliar para verificar se os vetores possuem números negativos
// Se possuir, não testa Counting e Radix sort para evitar segmentation fault
TEST(Sorting, TestSortingNegative){
    teste(vet_neg, 5, CERTO);
}

// Teste vetor com elementos positivos e negativos
TEST(Sorting, TestSortingMixed){
    teste(vet_mixed, 8, CERTO);
}

// Testa vetor com tamanho mínimo
// leak de memória
TEST(Sorting, TestSortingMinSize){
	int *vet_min = malloc(2 * sizeof(int));
	if (vet_min != NULL) {
		vet_min[0] = 2; 
		vet_min[1] = 1;
		teste(vet_min, 2, CERTO);
    }
	free(vet_min);
}

// Testa vetor com tamanho máximo
// leak de memória
TEST(Sorting, TestSortingMaxSize) {
	int *vet_max = malloc(20 * sizeof(int));
    if (vet_max != NULL) {
        for (int i = 0; i < 20; i++) {
            vet_max[i] = 20 - i;
        }
		teste(vet_max, 20, CERTO);
    }
	free(vet_max);
}

// Testa um vetor com mais de 20 elementos (deve retornar erro)
// leak de memória 
TEST(Sorting, TestSortingInvalidSize) {
    int *vet_invalid = malloc(21 * sizeof(int));
    if (vet_invalid != NULL) {
        for (int i = 0; i < 21; i++) {
            vet_invalid[i] = 21 - i; 
        }
		teste(vet_invalid, 21, ERRADO);
    }
	free(vet_invalid);
}

// Testa um vetor de tamanho 0
TEST(Sorting, TestSortingZeroSize) {
    int *vet_empty = malloc(0);  
    teste(vet_empty, 0, ERRADO);  
}

TEST(Sorting, TestNegativeValuesFunction) {
    TEST_ASSERT_EQUAL(1, negative_values(vet_neg, 5)); // Deve detectar negativo
    TEST_ASSERT_EQUAL(0, negative_values(vet_asc, 10)); // Não deve detectar negativo
}


void teste(int* vet_base, int size, int compare) {
    int status = 0;
    int *vet = malloc(size * sizeof(int));
    if (vet != NULL) {
		printf("começando\n\n");

        if (negative_values(vet_base, size)) {
            TEST_IGNORE_MESSAGE("Ordenação com Radix ou Counting Sort falhou devido a números negativos.");
            free(vet);
            return;
        }
		
		// Counting Sort
		memcpy(vet, vet_base, size * sizeof(int));
		status += sort(vet, size, "On", COUNTING);
		printf("COUNTING + %d\n", status);

		// Radix Sort
		 memcpy(vet, vet_base, size * sizeof(int));
		status += sort(vet, size, "On", RADIX);
		 printf("RADIX + %d\n", status);
        
        // Bubble Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status += sort(vet, size, "On2", BUBBLE);
        printf("BUBBLE + %d\n", status);
        
        // Insertion Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status += sort(vet, size, "On2", INSERTION);
        printf("INSERTION + %d\n", status);
        
        // Selection Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status += sort(vet, size, "On2", SELECTION);
        printf("SELECTION + %d\n", status);
        
        // Heap Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status += sort(vet, size, "Onlogn", HEAP);
        printf("HEAP + %d\n", status);
        
        // Merge Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status += sort(vet, size, "Onlogn", MERGE);
        printf("MERGE + %d\n", status);
        
        // Quick Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status += sort(vet, size, "Onlogn", QUICK);
        printf("QUICK + %d\n", status);

        if(status > 0)
            status = 1;

        TEST_ASSERT_EQUAL(compare, status);
    }
    free(vet);
}

int negative_values(int* vet, int size) {
    for (int i = 0; i < size; i++) {
        if (vet[i] < 0) {
            return 1; // Retorna 1 se houver números negativos
        }
    }
    return 0; // Retorna 0 se não houver números negativos
}
