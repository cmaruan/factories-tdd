#if !defined(_FACTORIES_H_)
#define _FACTORIES_H_

#include "factories/product_factory.h"

// Struct to hold all future factories
struct Factories {
    struct ProductFactory *product;
};

// Static entrypoint for the factories
static struct Factories _factories = {
    .product = &_product_factory
};
static struct Factories *factories = &_factories;


#endif // _FACTORIES_H_
