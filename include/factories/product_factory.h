#if !defined(_PRODUCT_FACTORY_H)
#define _PRODUCT_FACTORY_H

#include "models/product.h"

// The struct holding methods to operate on products
struct ProductFactory {
    void *(*create)(void);
};

void *ProductFactory_create() {
    static product_t product;
    product.primary_key = 1;
    return &product;
}

static struct ProductFactory _product_factory = {
    .create = ProductFactory_create
};


#endif // _PRODUCT_FACTORY_H