#include <stddef.h>

#define ASSERT(expr) if(!(expr)) { _test_failed += 1; return; }

static int _test_failed = 0;

typedef struct {
    size_t primary_key;
} product_t;

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

// Struct to hold all future factories
struct Factories {
    struct ProductFactory *product;
};

// Static entrypoint for the factories
static struct Factories _factories = {
    .product = &_product_factory
};
static struct Factories *factories = &_factories;


void test_can_create_product(void)
{
    product_t *product = (product_t *)factories->product->create();
    ASSERT(product != NULL)
    ASSERT(product->primary_key > 0);
}


int main(void)
{
    _test_failed = 0;
    test_can_create_product();
    return _test_failed;
}