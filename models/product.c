#include "models/product.h"

typedef struct {
    struct ClassType *type;
    size_t primary_key;
} product_t;

static struct ClassType _ProductType = {
    .size = sizeof(product_t),
    .ctor = NULL,
    .dtor = NULL,
};
struct ClassType *ProductType = &_ProductType;

size_t ProductPrimaryKey(void *_product)
{
    product_t *product = _product;
    return product ? product->primary_key : 0U;
}

int ProductSetPrimaryKey(void *_product, size_t pk)
{
    product_t *product = _product;
    product->primary_key = pk;
    return 1;
}