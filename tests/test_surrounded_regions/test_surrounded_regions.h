#include <cppunit/extensions/HelperMacros.h>

class test_surrounded_regions : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_surrounded_regions);
	CPPUNIT_TEST(first_test);

	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void first_test();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_surrounded_regions);
