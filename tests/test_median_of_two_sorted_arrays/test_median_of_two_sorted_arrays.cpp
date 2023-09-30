#include <cppunit/TestAssert.h>

#include "../../src/median_of_two_sorted_arrays/assignment.h"
#include "test_median_of_two_sorted_arrays.h"

void
test_median_of_two_sorted_arrays::first_test()
{
	auto result = median({ 1, 3 }, { 2 });

	CPPUNIT_ASSERT_EQUAL(result, 2.0);
}

void
test_median_of_two_sorted_arrays::second_test()
{
	auto result = median({ 1, 2 }, { 3, 4 });

	CPPUNIT_ASSERT_EQUAL(result, 2.5);
}
