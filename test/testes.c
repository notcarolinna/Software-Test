#include "unity.h"
#include "unity_fixture.h"

const char* tipos[] = {"regular", "estudante", "aposentado", "VIP"};
//const char* lista[] = {"regular", "regular", "aposentado", "VIP"};
//const float valores[] = {0.01, 5000.0, 10000.0, 20000.0, 30000.0, 40000.0, 50000.0, 60000.0, 70000.0, 80000.0, 90000.0, 99999.0};
const float valores[] = {0.01, 5999.0, 15000.0, 25000.0, 35000.0, 45000.0, 50000.0, 65000.0, 75000.0, 85000.0, 95000.0, 99999.0};


TEST_GROUP(Foo);

TEST_SETUP(Foo)
{
}

TEST_TEAR_DOWN(Foo)
{
}

TEST(Foo, TestFoo1)
{
    printf("\n");
    float pagamento = valores[0];
    char tipo[15];  
    int i = 1;
    int j = 0;
    while (i <= 12){
        while (j<4){
            sprintf(tipo, tipos[j]);
            printf("%f - %s\n", pagamento, tipo);
            TEST_ASSERT_EQUAL(0, payment(pagamento,tipo));
            j++;
        }
        printf("teste tipo errado: %f - %s\n\n\n", pagamento, "xablau");
        TEST_ASSERT_EQUAL(2, payment(pagamento,"!"));

        printf("\nteste null: %f - NULL\n",pagamento);
        TEST_ASSERT_EQUAL(2, payment(pagamento, NULL));

        pagamento = valores[i];
        j = 0;  
        i++; 
    }
    while(j<4){
        sprintf(tipo, tipos[j]);
        printf("teste valor negativo: %f - %s\n", -0.1, tipo);
        TEST_ASSERT_EQUAL(1, payment(-0.1,tipo));

        printf("teste valor maior: %f - %s\n", 99999.9, tipo);
        TEST_ASSERT_EQUAL(1, payment(99999.9,tipo));

        printf("\nteste com 0: 0 - %s\n", tipo);
        TEST_ASSERT_EQUAL(1,payment(0, "tipo"));

        j++;
    }

        printf("teste valor negativo: %f - NULL\n", -0.1);
        TEST_ASSERT_EQUAL(1, payment(-0.1,NULL));

        printf("teste valor maior: %f - NULL\n", 99999.9);
        TEST_ASSERT_EQUAL(1, payment(99999.9,NULL));

        printf("\nteste com 0: 0 - NULL\n");
        TEST_ASSERT_EQUAL(1,payment(0, "NULL"));

        printf("case sensitivity: 5000 - REGULAR\n");
        TEST_ASSERT_EQUAL(2, payment(5000, "REGULAR"));

}