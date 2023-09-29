#include <cppunit/extensions/HelperMacros.h>

class test_count_and_say : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_count_and_say);
	CPPUNIT_TEST(test_count_and_say_single_input);
	CPPUNIT_TEST(test_count_and_say_nultiple_inputs);

	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_count_and_say_single_input();
	void test_count_and_say_nultiple_inputs();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_count_and_say);
