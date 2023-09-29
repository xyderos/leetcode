#include <cppunit/TestAssert.h>

#include "../../src/anagrams/assignment.h"
#include "test_anagrams.h"

#include <algorithm>
#include <vector>

static auto
compare_vectors(const std::vector<std::vector<std::string>> &either,
    const std::vector<std::vector<std::string>> &other) -> bool
{
	std::vector<std::string> flat_either, flat_other;

	std::for_each(either.begin(), either.end(),
	    [&](const std::vector<std::string> &v) {
		    flat_either.insert(flat_either.end(), v.begin(), v.end());
	    });

	std::for_each(other.begin(), other.end(),
	    [&](const std::vector<std::string> &v) {
		    flat_other.insert(flat_other.end(), v.begin(), v.end());
	    });

	std::sort(flat_either.begin(), flat_either.end());
	std::sort(flat_other.begin(), flat_other.end());

	return flat_either == flat_other;
}

void
test_anagrams::test_anagrams_with_valid_input()
{
	std::vector<std::string> input { "eat", "tea", "tan", "ate", "nat",
		"bat" };

	auto result = group_anagrams(input);

	std::vector<std::vector<std::string>> expected { { "bat" },
		{ "nat", "tan" }, { "ate", "eat", "tea" } };

	CPPUNIT_ASSERT(compare_vectors(result, expected));
}

void
test_anagrams::test_anagrams_with_empty_input()
{
	std::vector<std::string> input { "" };

	auto result = group_anagrams(input);

	std::vector<std::vector<std::string>> expected { { "" } };

	CPPUNIT_ASSERT(compare_vectors(result, expected));
}

void
test_anagrams::test_anagrams_with_single_input()
{
	std::vector<std::string> input { "a" };

	auto result = group_anagrams(input);

	std::vector<std::vector<std::string>> expected { { "a" } };

	CPPUNIT_ASSERT(compare_vectors(result, expected));
}
