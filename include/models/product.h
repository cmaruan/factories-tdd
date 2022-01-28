#if !defined(_PRODUCT_H_)
#define _PRODUCT_H_

#include <stddef.h>
#include "type.h"

extern struct ClassType *ProductType;

size_t  ProductPrimaryKey(void *self);
int     ProductSetPrimaryKey(void *self, size_t pk);
double  ProductPrice(void *self);

#endif // _PRODUCT_H_
