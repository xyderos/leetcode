#include <cppunit/extensions/HelperMacros.h>

class test_add_two_numbers : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_add_two_numbers);
	CPPUNIT_TEST(test_add_two_numbers_first_case);
	CPPUNIT_TEST(test_add_two_numbers_second_case);
	CPPUNIT_TEST(test_add_two_numbers_third_case);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_add_two_numbers_first_case();
	void test_add_two_numbers_second_case();
	void test_add_two_numbers_third_case();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_add_two_numbers);
