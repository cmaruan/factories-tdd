#if !defined(_UNITTESTS_H_)
#define _UNITTESTS_H_

#include <stdio.h>

#define ASSERT(expr)                                               \
    do                                                             \
    {                                                              \
        if (!UnittestValidate(#expr, !!(expr), __FILE__, __LINE__)) \
            return;                                                \
    } while (0)
#define TEST_INIT()       \
    do                    \
    {                     \
        _test_failed = 0; \
    } while (0)
#define TEST_FAILED() (_test_failed)

static int _test_failed = 0;

int UnittestValidate(
    const char *expr,
    int result,
    const char *file,
    int line)
{
    if (result == 0)
    {
        fprintf(stderr, "Assertion failed (%s:%d): `%s`\n", file, line, expr);
        _test_failed += 1;
        return 0;
    }
    return 1;
}

#endif // _UNITTESTS_H_
