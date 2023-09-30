#include <cppunit/extensions/HelperMacros.h>

class test_zig_zag : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_zig_zag);
	CPPUNIT_TEST(test_zig_zag_three_rows);
	CPPUNIT_TEST(test_zig_zag_four_rows);

	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_zig_zag_three_rows();
	void test_zig_zag_four_rows();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_zig_zag);
