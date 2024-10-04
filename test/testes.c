#include "unity.h"
#include "unity_fixture.h"
#include "../src/sort.h"

	int vet1[4] = {3,2,4,1};
	int vet2[4] = {3,2,4,1};
	int vet3[4] = {3,2,4,1};
	int vet4[4] = {3,2,4,1};
	int vet5[4] = {3,2,4,1};
	int vet6[4] = {3,2,4,1};
	int vet7[4] = {3,2,4,1};
	int vet8[4] = {3,2,4,1}; 

TEST_GROUP(Sorting);

TEST_SETUP(Sorting)
{
}

TEST_TEAR_DOWN(Sorting)
{
}

// Testa ordenação
TEST(Sorting, TestSorting1){
    
	int size = 4;
	
    sort(vet1, size, "On", COUNTING);      
	sort(vet2, size, "On", RADIX);       
	sort(vet3, size, "On2", BUBBLE);       
	sort(vet4, size, "On2", INSERTION);    
	sort(vet5, size, "On2", SELECTION);   
	sort(vet6, size, "Onlogn", HEAP);     
	sort(vet7, size, "Onlogn", MERGE);    
	sort(vet8, size, "Onlogn", QUICK);    

	check_sorted(vet1, size);
	check_sorted(vet2, size);
	check_sorted(vet3, size);
	check_sorted(vet4, size);
	check_sorted(vet5, size);
	check_sorted(vet6, size);
	check_sorted(vet7, size);
	check_sorted(vet8, size);
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
