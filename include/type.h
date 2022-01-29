#if !defined(_TYPE_H_)
#define _TYPE_H_

#include <stddef.h>
#include <stdarg.h>

struct ClassType {
    size_t size;
    void *(*ctor)(void *self, va_list *ap);
    void *(*dtor)(void *self);
    int (*has_attr)(const void *self, const char *attr);
    int (*set_attr)(void *self, const char *attr, va_list *ap);
    int (*get_attr)(const void *self, const char *attr, va_list *ap);
};

// Allocates a new memory block and call the constructor of a given type
void *New(struct ClassType *type, ...);

// Calls the destructor of an object and possibly free the resources.
// It must get a valid pointer whose value is set to NULL 
void Destroy(void **self);

// Checks if an object is an instantiation of a given type
int InstanceOf(const void *self, const struct ClassType *type);

// Returns true if an attribute is defined on an object
int HasAttr(const void *self, const char *attr);

// Returns via paramenter pointer the content of 
int GetAttr(const void *self, const char *attr, ...);

// Set a given attribute on the object
int SetAttr(void *self, const char *attr, ...);


#endif // _TYPE_H_
