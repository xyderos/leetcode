#include <cppunit/extensions/HelperMacros.h>

class test_rotate_image : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_rotate_image);
	CPPUNIT_TEST(test_rotate_image_case_3x3);
	CPPUNIT_TEST(test_rotate_image_case_4x4);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_rotate_image_case_3x3();
	void test_rotate_image_case_4x4();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_rotate_image);
