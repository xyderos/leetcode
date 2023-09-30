#include <cppunit/extensions/HelperMacros.h>

class test_reverse_integer : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_reverse_integer);
	CPPUNIT_TEST(test_reverse_integer_positive);
	CPPUNIT_TEST(test_reverse_integer_negative);
	CPPUNIT_TEST(test_reverse_integer_trailing_zeroes);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_reverse_integer_positive();
	void test_reverse_integer_negative();
	void test_reverse_integer_trailing_zeroes();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_reverse_integer);
