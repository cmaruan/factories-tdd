#if !defined(_PRODUCT_FACTORY_H)
#define _PRODUCT_FACTORY_H

#include "models/product.h"

// The struct holding methods to operate on products
struct ProductFactory {
    void *(*create)(void);
    void (*destroy)(void **);
};

extern struct ProductFactory _product_factory;


#endif // _PRODUCT_FACTORY_H