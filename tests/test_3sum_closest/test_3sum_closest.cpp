#include "../../src/3sum_closest/3sum_closest.h"
#include "test_3sum_closest.h"

#include <algorithm>
#include <functional>
#include <set>
#include <vector>

void
test_3sum_closest::test_quantrant_should_produce_valid_result()
{
	std::vector<int> input { -1, 2, 1, -4 };
	int target = 1;

	auto result = quantrant(input, target);

	auto expected = 2;

	CPPUNIT_ASSERT_EQUAL(expected, result);
}
