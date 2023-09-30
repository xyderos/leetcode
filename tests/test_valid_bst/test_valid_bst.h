#include <cppunit/extensions/HelperMacros.h>

class test_valid_bst : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_valid_bst);
	CPPUNIT_TEST(test_valid_bst_with_valid_bst_should_be_okay);
	CPPUNIT_TEST(test_valid_bst_with_invalid_bst_should_not_be_okay);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_valid_bst_with_valid_bst_should_be_okay();
	void test_valid_bst_with_invalid_bst_should_not_be_okay();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_valid_bst);
