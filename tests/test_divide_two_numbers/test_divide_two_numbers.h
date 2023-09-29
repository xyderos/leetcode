#include <cppunit/extensions/HelperMacros.h>

class test_divide_two_numbers : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_divide_two_numbers);
	CPPUNIT_TEST(test_division_negative);
	CPPUNIT_TEST(test_division_positive);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_division_negative();
	void test_division_positive();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_divide_two_numbers);
