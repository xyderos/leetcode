#include <cppunit/extensions/HelperMacros.h>

class test_substring_with_concat_of_all_words : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_substring_with_concat_of_all_words);
	CPPUNIT_TEST(test_concat_substring_case_1);
	CPPUNIT_TEST(test_concat_substring_case_2);
	CPPUNIT_TEST(test_concat_substring_case_3);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_concat_substring_case_1();
	void test_concat_substring_case_2();
	void test_concat_substring_case_3();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_substring_with_concat_of_all_words);
