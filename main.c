#include "unittest.h"
#include "factories/factories.h"
#include "type.h"


void test_can_create_product_from_factory(void)
{
    object_t *product = factories->product->create();
    ASSERT(product != NULL)
    ASSERT(ProductPrimaryKey(product) != 0);
}

void test_can_destroy_product_from_factory(void)
{
    object_t *product = factories->product->create();
    factories->product->destroy(&product);
    ASSERT(product == NULL);
}

void test_create_product_with_price(void)
{
    object_t *product = New(ProductType, "price", 25);
    ASSERT(ProductPrice(product) == 25);
}

int main(void)
{
    TEST_INIT();
    test_can_create_product_from_factory();
    test_can_destroy_product_from_factory();
    test_create_product_with_price();
    return TEST_FAILED();
}