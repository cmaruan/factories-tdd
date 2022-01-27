#define ASSERT(expr) if(!(expr)) { _test_failed += 1; return; }

static int _test_failed = 0;

// The struct holding methods to operate on products
struct ProductFactory {
    void *(*create)(void);
};

// Struct to hold all future factories
struct Factories {
    struct ProductFactory *product;
};

// Static entrypoint for the factories
static struct Factories _factories;
static struct Factories *factories = &_factories;


void test_can_create_product(void)
{
    void *product = factories->product->create();
    // ASSERT(product->primary_key > 0);
}


int main(void)
{
    _test_failed = 0;
    test_can_create_product();
    return _test_failed;
}