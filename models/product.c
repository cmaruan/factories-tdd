#include <stddef.h>
#include <assert.h>
#include <string.h>
#include "models/product.h"

typedef struct {
    struct ClassType *type;
    size_t primary_key;
    double price;
} product_t;


#define ATTR_INFO(struct, type, field) {#field, sizeof(type), offsetof(struct, field)}

struct {
    const char * attr_name;
    size_t attr_size;
    size_t attr_offset;
} offsets[] = {
    ATTR_INFO(product_t, size_t, primary_key),
    ATTR_INFO(product_t, double, price)
};

size_t offsets_size = sizeof(offsets)/sizeof(offsets[0]);

static size_t _ProductType_attr_index(const char * attr) {
    size_t start = 0;
    size_t end = offsets_size;
    size_t i;
    for (i = start; i < end; i++)
        if (strcmp(attr, offsets[i].attr_name) == 0)
            break;
    return i;
}

void * ProductType_ctor(void *_self, va_list *ap);
int ProductType_has_attr(const void *self, const char *attr);
int ProductType_get_attr(const void *self, const char *attr, va_list *ap);
int ProductType_set_attr(void *self, const char *attr, va_list *ap);

static struct ClassType _ProductType = {
    .size = sizeof(product_t),
    .ctor = ProductType_ctor,
    .dtor = NULL,
    .set_attr = ProductType_set_attr,
    .has_attr = ProductType_has_attr,
    .get_attr = ProductType_get_attr,
};
struct ClassType *ProductType = &_ProductType;


void * ProductType_ctor(void *_self, va_list *ap)
{
    assert(_self && InstanceOf(_self, ProductType));
    product_t *self = _self;
    int args = va_arg(*ap, int);
    int rv = 1;
    for (int a = 0; a < args && rv; a++) {
        const char *attr = va_arg(*ap, const char *);
        rv = ProductType_set_attr(self, attr, ap);
    }
    return rv ? self : NULL;
}

int ProductType_set_attr(void *_self, const char *attr, va_list *ap)
{
    assert(_self && InstanceOf(_self, ProductType));
    product_t *self = _self;
    int rv = 1;
    if (strcmp(attr, "price") == 0) {
        double price = va_arg(*ap, double);
        self->price = price;
    } else if (strcmp(attr, "pk") == 0) {
        int pk = va_arg(*ap, int);
        self->primary_key = pk;
    } else {
        rv = 0;
    }
    return rv;
}


int ProductType_has_attr(const void *self, const char *attr)
{
    return _ProductType_attr_index(attr) != offsets_size;
}

int ProductType_get_attr(const void *self, const char *attr, va_list *ap)
{
    size_t i = _ProductType_attr_index(attr);
    if (i == offsets_size)
        return 0;
    void *ptr = va_arg(*ap, void *);
    memcpy(ptr, self + offsets[i].attr_offset, offsets[i].attr_size);
    return 1;
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