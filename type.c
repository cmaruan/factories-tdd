#include <assert.h>
#include <stdlib.h>

#include "type.h"


#define GET_TYPE_OF(self)       (*(struct ClassType **)(self))
#define SET_TYPE_AS(obj, type)  (GET_TYPE_OF(obj) = (type))


void *New(struct ClassType *type, ...)
{
    assert(type && type->size);
    void *obj = calloc(1, type->size);
    SET_TYPE_AS(obj, type);
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
    struct ClassType *type = GET_TYPE_OF(*self);
    if (type && type->dtor) {
        *self = type->dtor(*self);
    }
    free(*self);
    *self = NULL;
}


int InstanceOf(const void *self, const struct ClassType *type)
{
    assert(type);
    return self != NULL && GET_TYPE_OF(self) == type;
}