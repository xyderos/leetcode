#include <cppunit/TestAssert.h>

#include "../../src/divide_two_numbers/assignment.h"
#include "test_divide_two_numbers.h"

void
test_divide_two_numbers::test_division_negative()
{
	auto result = divide(10, 3);

	CPPUNIT_ASSERT_EQUAL(3, result);
}

void
test_divide_two_numbers::test_division_positive()
{
	auto result = divide(7, -3);

	CPPUNIT_ASSERT_EQUAL(-2, result);
}
