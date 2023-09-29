#include <cppunit/TestAssert.h>

#include "../../src/non_decreasing/assignment.h"
#include "test_non_decreasing.h"

void
test_non_decreasing::first_test()
{

	auto result = non_decreasing({ 4, 2, 3 });

	CPPUNIT_ASSERT(result);
}

void
test_non_decreasing::second_test()
{
	auto result = non_decreasing({ 4, 2, 1 });

	CPPUNIT_ASSERT(!result);
}
