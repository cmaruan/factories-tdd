#include "factories/factories.h"

// Static entrypoint for the factories
static struct Factories _factories = {
    .product = &_product_factory
};
struct Factories *factories = &_factories;