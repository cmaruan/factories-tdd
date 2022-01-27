#if !defined(_UNITTESTS_H_)
#define _UNITTESTS_H_

#define ASSERT(expr)    if(!(expr)) { _test_failed += 1; return; }
#define TEST_INIT()     do { _test_failed = 0; } while (0)
#define TEST_FAILED()   (_test_failed > 0)

static int _test_failed = 0;

#endif // _UNITTESTS_H_
