#include <cppunit/extensions/HelperMacros.h>

class test_3sum : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_3sum);
	CPPUNIT_TEST(
	    test_3sum_with_normal_numbers_should_return_the_correct_result);
	CPPUNIT_TEST(
	    test_3sum_with_invalid_numbers_should_return_an_empty_list);
	CPPUNIT_TEST(test_3sum_with_zeroes_should_return_zero_result);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_3sum_with_normal_numbers_should_return_the_correct_result();
	void test_3sum_with_invalid_numbers_should_return_an_empty_list();
	void test_3sum_with_zeroes_should_return_zero_result();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_3sum);
