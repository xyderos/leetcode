#include "assignment.h"

#include <algorithm>

auto
permutations(const std::vector<int> &container) -> std::vector<std::vector<int>>
{
	auto tmp = container;
	std::sort(tmp.begin(), tmp.end());

	std::vector<std::vector<int>> result {};

	result.emplace_back(tmp);

	while (std::next_permutation(tmp.begin(), tmp.end())) {
		result.emplace_back(tmp);
	}

	return result;
}
