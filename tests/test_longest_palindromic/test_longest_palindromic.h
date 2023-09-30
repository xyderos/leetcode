#include <cppunit/extensions/HelperMacros.h>

class test_longest_palindromic : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_longest_palindromic);
	CPPUNIT_TEST(test_longest_palindromic_case_1);
	CPPUNIT_TEST(test_longest_palindromic_case_2);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_longest_palindromic_case_1();
	void test_longest_palindromic_case_2();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_longest_palindromic);
