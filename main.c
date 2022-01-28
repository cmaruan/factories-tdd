
#include "unittest.h"
#include "factories/factories.h"


void test_can_create_product(void)
{
    product_t *product = factories->product->create();
    ASSERT(product != NULL)
    ASSERT(product->primary_key > 0);
}

void test_can_destroy_product(void)
{
    product_t *product = factories->product->create();
    factories->product->destroy((void **)&product);
    ASSERT(product == NULL);
}


int main(void)
{
    TEST_INIT();
    test_can_create_product();
    test_can_destroy_product();
    return TEST_FAILED();
}