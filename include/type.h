#if !defined(_TYPE_H_)
#define _TYPE_H_

#include <stddef.h>
#include <stdarg.h>

struct ClassType {
    size_t size;
    void *(*ctor)(void *self, va_list *ap);
    void *(*dtor)(void *self);
};

void *New(struct ClassType *type, ...);
void Destroy(void **self);
int InstanceOf(const void *self, const struct ClassType *type);


#endif // _TYPE_H_
