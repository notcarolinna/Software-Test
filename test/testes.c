#include "unity.h"
#include "unity_fixture.h"
#include "../src/sort.h"

TEST_GROUP(Sorting);

TEST_SETUP(Sorting)
{
}

TEST_TEAR_DOWN(Sorting)
{
}

// Testa Ordenação

TEST(Sorting, TestSorting1) {
	int vet1[4] = {3,2,4,1};
	int vet2[4] = {3,2,4,1};
	int vet3[4] = {3,2,4,1};
	int vet4[4] = {3,2,4,1};
	int vet5[4] = {3,2,4,1};
	int vet6[4] = {3,2,4,1};
	int vet7[4] = {3,2,4,1};
	int vet8[4] = {3,2,4,1}; 
    
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

void check_sorted(int vet[], int size) {
	for(int i = 0; i < size; i++) {
		TEST_ASSERT_EQUAL(i + 1, vet[i]);
	}
}
