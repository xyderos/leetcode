#include "../../src/3sum/3sum.h"
#include "test_3sum.h"

#include <algorithm>
#include <functional>
#include <set>
#include <vector>

static auto
containers_have_the_same_content(const std::set<std::vector<int>> &c1,
    const std::set<std::vector<int>> &c2) -> bool
{
	std::set<std::vector<int>> s1, s2;

	for (std::vector<int> e : c1) {
		std::sort(e.begin(), e.end());
		s1.emplace(e);
	}

	for (std::vector<int> e : c2) {
		std::sort(e.begin(), e.end());
		s2.emplace(e);
	}

	if (s1.size() != s2.size()) {
		return false;
	}

	for (const std::vector container : s1) {
		if (!s2.contains(container)) {
			return false;
		}
	}

	return true;
}

void
test_3sum::test_3sum_with_normal_numbers_should_return_the_correct_result()
{
	std::vector<int> input { -1, 0, 1, 2, -1, -4 };

	auto result = three_sum(input);

	auto expected = std::set<std::vector<int>> { { -1, -1, 2 },
		{
		    -1,
		    1,
		    0,
		} };

	CPPUNIT_ASSERT(containers_have_the_same_content(result, expected));
}

void
test_3sum::test_3sum_with_invalid_numbers_should_return_an_empty_list()
{
	std::vector<int> input { 0, 1, 1 };

	auto result = three_sum(input);

	auto expected = std::set<std::vector<int>> {};

	CPPUNIT_ASSERT(containers_have_the_same_content(result, expected));
}

void
test_3sum::test_3sum_with_zeroes_should_return_zero_result()
{
	std::vector<int> input { 0, 0, 0 };

	auto result = three_sum(input);

	auto expected = std::set<std::vector<int>> { { 0, 0, 0 } };

	CPPUNIT_ASSERT(containers_have_the_same_content(result, expected));
}
