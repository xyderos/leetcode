#include <cppunit/extensions/HelperMacros.h>

class test_find_first_and_last_position_in_sorted_array
    : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_find_first_and_last_position_in_sorted_array);
	CPPUNIT_TEST(find_targets_case_1);
	CPPUNIT_TEST(find_targets_case_2);
	CPPUNIT_TEST(find_targets_case_3);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void find_targets_case_1();
	void find_targets_case_2();
	void find_targets_case_3();
};

CPPUNIT_TEST_SUITE_REGISTRATION(
    test_find_first_and_last_position_in_sorted_array);
