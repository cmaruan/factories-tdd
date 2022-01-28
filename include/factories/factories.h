#if !defined(_FACTORIES_H_)
#define _FACTORIES_H_

#include "factories/product_factory.h"

// Struct to hold all future factories
struct Factories {
    struct ProductFactory *product;
};

extern struct Factories *factories;


#endif // _FACTORIES_H_
