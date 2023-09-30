#include <cppunit/TestAssert.h>

#include "../../src/zig_zag/assignment.h"
#include "test_zig_zag.h"

void
test_zig_zag::test_zig_zag_three_rows()
{
	std::string input("PAYPALISHIRING"), output("PAHNAPLSIIGYIR");

	auto result = zig_zag(input, 3);

	CPPUNIT_ASSERT_EQUAL(result, output);
}

void
test_zig_zag::test_zig_zag_four_rows()
{
	std::string input("PAYPALISHIRING"), output("PINALSIGYAHRPI");

	auto result = zig_zag(input, 4);

	CPPUNIT_ASSERT_EQUAL(result, output);
}
