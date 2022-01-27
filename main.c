#define ASSERT(expr) if(!(expr)) { _test_failed += 1; return; }

static int _test_failed = 0;

void test_can_create_product(void)
{
    ASSERT(12 == 13);
    // void *product = factories->product->create();
    // ASSERT(product->primary_key > 0);
}


int main(void)
{
    _test_failed = 0;
    test_can_create_product();
    return _test_failed;
}