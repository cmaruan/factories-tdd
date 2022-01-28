#if !defined(_TYPE_H_)
#define _TYPE_H_

#include <stddef.h>
#include <stdarg.h>

typedef void object_t;
typedef void* type_id_t;

struct ClassType {
    size_t size;
    type_id_t id;
    object_t *(*ctor)(object_t *self, va_list *ap);
    object_t *(*dtor)(object_t *self);
};

object_t *New(struct ClassType *type, ...);
void Destroy(object_t **self);


#endif // _TYPE_H_
