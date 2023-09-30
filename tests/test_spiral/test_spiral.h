#include <cppunit/extensions/HelperMacros.h>

class test_spiral : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_spiral);
	CPPUNIT_TEST(test_spiral_3x3);
	CPPUNIT_TEST(test_spiral_3x4);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_spiral_3x3();
	void test_spiral_3x4();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_spiral);
