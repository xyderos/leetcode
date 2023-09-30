#include <cppunit/TestAssert.h>

#include "../../src/atoi/assignment.h"
#include "test_atoi.h"

void
test_atoi::first_test()
{
	auto result = my_atoi("42");

	CPPUNIT_ASSERT_EQUAL(42, result);
}

void
test_atoi::second_test()
{
	auto result = my_atoi("   -42");

	CPPUNIT_ASSERT_EQUAL(-42, result);
}

void
test_atoi::third_test()
{
	auto result = my_atoi("4193 with words");

	CPPUNIT_ASSERT_EQUAL(4193, result);
}
