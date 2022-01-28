#include "factories/product_factory.h"

void *ProductFactory_create();

struct ProductFactory _product_factory = {
    .create = ProductFactory_create
};

void *ProductFactory_create() {
    static product_t product;
    product.primary_key = 1;
    return &product;
}
