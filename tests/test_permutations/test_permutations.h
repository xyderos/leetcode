#include <cppunit/extensions/HelperMacros.h>

class test_permutations : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_permutations);
	CPPUNIT_TEST(first_test);
	CPPUNIT_TEST(second_test);

	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void first_test();
	void second_test();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_permutations);
