#if !defined(_PRODUCT_H_)
#define _PRODUCT_H_

#include <stddef.h>
#include "type.h"

extern struct ClassType *ProductType;

size_t ProductPrimaryKey(void *product);
int ProductSetPrimaryKey(void *_product, size_t pk);


#endif // _PRODUCT_H_
