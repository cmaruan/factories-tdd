#include "models/product.h"

typedef struct {
    size_t primary_key;
} product_t;

size_t ProductPrimaryKey(void *_product)
{
    product_t *product = _product;
    return product ? product->primary_key : 0U;
}