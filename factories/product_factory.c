#include "factories/product_factory.h"

void *ProductFactory_create();
void ProductFactory_destroy(void **);

struct ProductFactory _product_factory = {
    .create = ProductFactory_create,
    .destroy = ProductFactory_destroy,
};

void *ProductFactory_create() {
    void *obj = New(ProductType, 1, "pk", 1);
    return obj;
}

void ProductFactory_destroy(void **product_ptr) {
    Destroy(product_ptr);
}
