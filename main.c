
#include "unittest.h"
#include "factories/factories.h"


void test_can_create_product(void)
{
    product_t *product = (product_t *)factories->product->create();
    ASSERT(product != NULL)
    ASSERT(product->primary_key > 0);
}


int main(void)
{
    TEST_INIT();
    test_can_create_product();
    return TEST_FAILED();
}