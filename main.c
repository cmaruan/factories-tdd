
#include "unittest.h"
#include "factories/factories.h"


void test_can_create_product(void)
{
    void *product = factories->product->create();
    ASSERT(product != NULL)
    ASSERT(ProductPrimaryKey(product) != 0);
}

void test_can_destroy_product(void)
{
    void *product = factories->product->create();
    factories->product->destroy(&product);
    ASSERT(product == NULL);
}



int main(void)
{
    TEST_INIT();
    test_can_create_product();
    test_can_destroy_product();
    return TEST_FAILED();
}