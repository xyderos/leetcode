#include <cppunit/extensions/HelperMacros.h>

class test_integer_to_roman : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_integer_to_roman);
	CPPUNIT_TEST(test_roman_to_int_single_digit);
	CPPUNIT_TEST(test_roman_to_int_two_digits);
	CPPUNIT_TEST(test_roman_to_int_three_digits);
	CPPUNIT_TEST(test_roman_to_int_four_digits);

	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_roman_to_int_single_digit();
	void test_roman_to_int_two_digits();
	void test_roman_to_int_three_digits();
	void test_roman_to_int_four_digits();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_integer_to_roman);
