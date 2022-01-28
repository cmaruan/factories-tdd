#include <assert.h>
#include "models/product.h"

typedef struct {
    struct ClassType *type;
    size_t primary_key;
    double price;
} product_t;


static struct ClassType _ProductType = {
    .size = sizeof(product_t),
    .ctor = NULL,
    .dtor = NULL,
};
struct ClassType *ProductType = &_ProductType;

size_t ProductPrimaryKey(void *_self)
{
    assert(_self);
    product_t *self = _self;
    return self->primary_key;
}

int ProductSetPrimaryKey(void *_self, size_t pk)
{
    assert(_self);
    product_t *self = _self;
    self->primary_key = pk;
    return 1;
}

double ProductPrice(void *_self) {
    assert(_self);
    product_t *self = _self;
    return self->price;
}