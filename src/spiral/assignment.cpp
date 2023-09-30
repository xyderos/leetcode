#include "assignment.h"

#include <algorithm>
#include <cstddef>
#include <iostream>

static auto
update_accumulator(std::vector<std::vector<int>> &accumulator)
    -> std::vector<std::vector<int>>
{
	std::vector<std::vector<int>> result {};
	std::for_each(accumulator.begin() + 1, accumulator.end() - 1,
	    [&](std::vector<int> c) {
		    result.emplace_back(c.begin() + 1, c.end() - 1);
	    });

	return result;
}

auto
spiral(const std::vector<std::vector<int>> &container) -> std::vector<int>
{
	std::vector<int> result;

	auto cpy = container;

	while (!cpy.empty()) {

		// always start from the upper side
		result.insert(result.end(), cpy.at(0).begin(), cpy.at(0).end());

		if (result.size() ==
		    container.at(0).size() * container.size()) {
			break;
		}

		// go to the right side

		// special case, since you need to iterate from pos 1 to pos
		// size -2 we need to handle it differently
		if (cpy.at(0).size() - 1 == 2) {
			result.emplace_back(cpy.at(1).at(cpy.at(0).size() - 1));
		} else {
			for (size_t i = 1; i < cpy.at(0).size() - 2; i++) {

				result.emplace_back(
				    cpy.at(i).at(cpy.at(0).size() - 1));
			}
		}

		if (result.size() ==
		    container.at(0).size() * container.size()) {
			break;
		}

		// lower side
		result.insert(result.end(), cpy.at(cpy.size() - 1).rbegin(),
		    cpy.at(cpy.size() - 1).rend());

		if (result.size() ==
		    container.at(0).size() * container.size()) {
			break;
		}

		// left side
		// special case, since you need to iterate from pos size -2 to
		// pos 1 we need to handle it differently
		if (cpy.at(0).size() - 1 == 2) {
			result.emplace_back(cpy.at(1).at(0));
		} else {
			for (size_t i = cpy.at(0).size() - 2; i > 1; i--) {

				result.emplace_back(cpy.at(i - 1).at(0));
			}
		}

		if (result.size() ==
		    container.at(0).size() * container.size()) {
			break;
		}

		cpy = update_accumulator(cpy);
	}

	return result;
}
