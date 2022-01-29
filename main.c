#include "unittest.h"
#include "factories/factories.h"
#include "type.h"

void test_can_create_product_from_factory(void)
{
    void *product = factories->product->create();
    ASSERT(product != NULL);
    ASSERT(ProductPrimaryKey(product) != 0);
}

void test_can_destroy_product_from_factory(void)
{
    void *product = factories->product->create();
    factories->product->destroy(&product);
    ASSERT(product == NULL);
}

void test_create_product_with_price(void)
{
    void *product = New(ProductType, 1, "price", 25.0);
    ASSERT(ProductPrice(product) == 25.0);
    Destroy(&product);
}

void test_product_attributes_are_accessible(void)
{
    double price;
    void *product = New(ProductType, 0);
    ASSERT(HasAttr(product, "price") == 1);
    ASSERT(SetAttr(product, "price", 25.25) == 1);
    ASSERT(GetAttr(product, "price", &price) == 1);
    ASSERT(price == 25.25);
    Destroy(&product);
}

int main(void)
{
    TEST_INIT();
    test_can_create_product_from_factory();
    test_can_destroy_product_from_factory();
    test_create_product_with_price();
    test_product_attributes_are_accessible();
    return TEST_FAILED();
}