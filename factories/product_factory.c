#include "factories/product_factory.h"

void *ProductFactory_create();
void ProductFactory_destroy(void **);

struct ProductFactory _product_factory = {
    .create = ProductFactory_create,
    .destroy = ProductFactory_destroy,
};

void *ProductFactory_create() {
    static product_t product;
    product.primary_key = 1;
    return &product;
}

void ProductFactory_destroy(void **product_ptr) {
    *product_ptr = NULL;
}
