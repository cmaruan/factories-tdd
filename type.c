#include <assert.h>
#include <stdlib.h>


#include "type.h"

void *New(struct ClassType *type, ...)
{
    assert(type && type->size);
    void *obj = calloc(1, type->size);
    *(struct ClassType **)obj = type;
    if (type->ctor) {
        va_list ap;
        va_start(ap, type);
        obj = type->ctor(obj, &ap);
        va_end(ap);
    }
    return obj;
}
void Destroy(void **self)
{
    assert(self);
    struct ClassType *type = *(struct ClassType **)self;
    if (type && type->dtor) {
        *self = type->dtor(*self);
    }
    free(*self);
    *self = NULL;
}