#include <cppunit/TestAssert.h>

#include "../../src/find_min_rotated_array/assignment.h"
#include "test_find_min_rotated_array.h"

void
test_find_min_rotated_array::test_find_min_sorted_array_case()
{
	auto result = find_min({ 1, 3, 5 });

	CPPUNIT_ASSERT_EQUAL(1, result);
}

void
test_find_min_rotated_array::test_find_min_sorted_array_case_duplicates()
{
	auto result = find_min({ 2, 2, 2, 0, 1 });

	CPPUNIT_ASSERT_EQUAL(0, result);
}
