#include "../../src/addition/addition.h"
#include "test_addition.h"

void
test_addition::test_addition_should_return_the_sum()
{
	int expected = 2, result = addition::add(1, 1);

	CPPUNIT_ASSERT_EQUAL(expected, result);
}
