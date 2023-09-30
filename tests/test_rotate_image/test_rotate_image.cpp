#include <cppunit/TestAssert.h>

#include "../../src/rotate_image/assignment.h"
#include "test_rotate_image.h"

void
test_rotate_image::test_rotate_image_case_3x3()
{

	auto result = rotate({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });

	std::vector<std::vector<int>> expected { { 7, 4, 1 }, { 8, 5, 2 },
		{ 9, 6, 3 } };

	CPPUNIT_ASSERT(expected == result);
}

void
test_rotate_image::test_rotate_image_case_4x4()
{
	auto result = rotate({ { 5, 1, 9, 11 }, { 2, 4, 8, 10 },
	    { 13, 3, 6, 7 }, { 15, 14, 12, 16 } });

	std::vector<std::vector<int>> expected { { 15, 13, 2, 5 },
		{ 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 } };

	CPPUNIT_ASSERT(expected == result);
}
