#include <cppunit/extensions/HelperMacros.h>

class test_addition : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_addition);
	CPPUNIT_TEST(test_addition_should_return_the_sum);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_addition_should_return_the_sum();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_addition);
