#include <cppunit/extensions/HelperMacros.h>

class test_3sum_closest : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_3sum_closest);
	CPPUNIT_TEST(test_quantrant_should_produce_valid_result);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_quantrant_should_produce_valid_result();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_3sum_closest);
