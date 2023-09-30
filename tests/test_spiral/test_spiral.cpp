#include <cppunit/TestAssert.h>

#include "../../src/spiral/assignment.h"
#include "test_spiral.h"

void
test_spiral::test_spiral_3x3()
{
	auto result = spiral({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });

	std::vector<int> expected { 1, 2, 3, 6, 9, 8, 7, 4, 5 };

	CPPUNIT_ASSERT(result == expected);
}

void
test_spiral::test_spiral_3x4()
{
	auto result = spiral(
	    { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } });

	std::vector<int> expected { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 };

	CPPUNIT_ASSERT(result == expected);
}
