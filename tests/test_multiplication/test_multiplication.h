#include <cppunit/extensions/HelperMacros.h>

class test_multiplication : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_multiplication);
	CPPUNIT_TEST(test_mult);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_mult();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_multiplication);
