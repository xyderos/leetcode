#include <cppunit/TestAssert.h>

#include "../../src/find_first_and_last_position_in_sorted_array/assignment.h"
#include "test_find_first_and_last_position_in_sorted_array.h"

void
test_find_first_and_last_position_in_sorted_array::find_targets_case_1()
{
	auto result = find_positions({ 5, 7, 7, 8, 8, 10 }, 8);

	std::pair<uint, uint> expected { 3, 4 };

	CPPUNIT_ASSERT(expected == result);
}

void
test_find_first_and_last_position_in_sorted_array::find_targets_case_2()
{
	auto result = find_positions({ 5, 7, 7, 8, 8, 10 }, 6);

	std::pair<uint, uint> expected { -1, -1 };

	CPPUNIT_ASSERT(expected == result);
}

void
test_find_first_and_last_position_in_sorted_array::find_targets_case_3()
{
	auto result = find_positions({}, 0);

	std::pair<uint, uint> expected { -1, -1 };

	CPPUNIT_ASSERT(expected == result);
}
