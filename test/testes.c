#include "unity.h"
#include "unity_fixture.h"
#include "../src/sort.h"

	int vet[][] = {
		{2,1},
		{3,2,1},
		{4,3,2,1},
		{5,4,3,2,1},
		{6,5,4,3,2,1},
		{7,6,5,4,3,2,1},
		{8,7,6,5,4,3,2,1},
		{9,8,7,6,5,4,3,2,1},
		{10,9,8,7,6,5,4,3,2,1},
		{11,10,9,8,7,6,5,4,3,2,1},
		{12,11,10,9,8,7,6,5,4,3,2,1},
		{13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{14,13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1},
		{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1}
	}
	// int vet2[2] = {2,1};
	// int vet3[3] = {3,2,1};
	// int vet4[4] = {4,3,2,1};
	// int vet5[5] = {5,4,3,2,1};
	// int vet6[6] = {6,5,4,3,2,1};
	// int vet7[7] = {7,6,5,4,3,2,1};
	// int vet8[8] = {8,7,6,5,4,3,2,1};
	// int vet9[9] = {9,8,7,6,5,4,3,2,1};
	// int vet10[10] = {10,9,8,7,6,5,4,3,2,1};
	// int vet11[11] = {11,10,9,8,7,6,5,4,3,2,1};
	// int vet12[12] = {12,11,10,9,8,7,6,5,4,3,2,1}; 
	// int vet13[13] = {13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet14[14] = {14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet15[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet16[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet17[17] = {17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet18[18] = {18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet19[19] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};
	// int vet20[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,4,1};

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

    
	// int size = 4;
	
    // sort(vet1, size, "On", COUNTING);      
	// sort(vet2, size, "On", RADIX);       
	// sort(vet3, size, "On2", BUBBLE);       
	// sort(vet4, size, "On2", INSERTION);    
	// sort(vet5, size, "On2", SELECTION);   
	// sort(vet6, size, "Onlogn", HEAP);     
	// sort(vet7, size, "Onlogn", MERGE);    
	// sort(vet8, size, "Onlogn", QUICK);    

	// check_sorted(vet1, size);
	// check_sorted(vet2, size);
	// check_sorted(vet3, size);
	// check_sorted(vet4, size);
	// check_sorted(vet5, size);
	// check_sorted(vet6, size);
	// check_sorted(vet7, size);
	// check_sorted(vet8, size);
}

void teste_foda_pra_caralho(string algoritmo, int tipo) {
	for(int i = 0; i <= 18; i++) {
		int size = i+2;
		int aux_vet[];
		memcpy(aux_vet, vet[i], size * sizeof(int));
		sort(aux_vet, size, algoritmo, tipo);
		check_sorted(aux_vet, size);
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
    
	int size = 4;
	
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
TEST(Sorting, TestSorting4){

}



void check_sorted(int vet[], int size) {
	for(int i = 0; i < size; i++) {
		TEST_ASSERT_EQUAL(i + 1, vet[i]);
	}
}
