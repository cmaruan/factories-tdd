#include <assert.h>
#include <string.h>
#include "models/product.h"

typedef struct {
    struct ClassType *type;
    size_t primary_key;
    double price;
} product_t;

void * ProductType_ctor(void *_self, va_list *ap);

static struct ClassType _ProductType = {
    .size = sizeof(product_t),
    .ctor = ProductType_ctor,
    .dtor = NULL,
};
struct ClassType *ProductType = &_ProductType;


void * ProductType_ctor(void *_self, va_list *ap)
{
    assert(_self && InstanceOf(_self, ProductType));
    product_t *self = _self;
    int args = va_arg(*ap, int);
    for (int a = 0; a < args; a++) {
        const char *field = va_arg(*ap, const char *);
        if (strcmp(field, "price") == 0) {
            double price = va_arg(*ap, double);
            self->price = price;
        }
    }
    return self;
}


size_t ProductPrimaryKey(void *_self)
{
    assert(_self && InstanceOf(_self, ProductType));
    product_t *self = _self;
    return self->primary_key;
}

int ProductSetPrimaryKey(void *_self, size_t pk)
{
    assert(_self && InstanceOf(_self, ProductType));
    product_t *self = _self;
    self->primary_key = pk;
    return 1;
}

double ProductPrice(void *_self) {
    assert(_self && InstanceOf(_self, ProductType));
    product_t *self = _self;
    return self->price;
}