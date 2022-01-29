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

int HasAttr(const void *self, const char *attr)
{
    assert(self);
    const struct ClassType *type = GET_TYPE_OF(self);
    return type->has_attr && type->has_attr(self, attr);
}

int GetAttr(const void *self, const char *attr, ...)
{
    assert(self);
    const struct ClassType *type = GET_TYPE_OF(self);
    int rv = 0;
    va_list ap;
    if (type && type->get_attr) {
        va_list ap;
        va_start(ap, attr);
        rv = type->get_attr(self, attr, &ap);
        va_end(ap);
    }
    return rv;
}
int SetAttr(void *self, const char *attr, ...)
{
    assert(self);
    const struct ClassType *type = GET_TYPE_OF(self);
    int rv = 0;
    va_list ap;
    if (type && type->set_attr) {
        va_list ap;
        va_start(ap, attr);
        rv = type->set_attr(self, attr, &ap);
        va_end(ap);
    }
    return rv;
}