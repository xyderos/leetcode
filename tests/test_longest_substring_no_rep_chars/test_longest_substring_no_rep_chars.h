#include <cppunit/extensions/HelperMacros.h>

class test_longest_substring_no_rep_chars : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_longest_substring_no_rep_chars);
	CPPUNIT_TEST(test_longest_sub_no_reps_simple);
	CPPUNIT_TEST(test_longest_sub_no_reps_simple_also);
	CPPUNIT_TEST(test_longest_sub_no_reps_sequence);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_longest_sub_no_reps_simple();
	void test_longest_sub_no_reps_simple_also();
	void test_longest_sub_no_reps_sequence();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_longest_substring_no_rep_chars);
