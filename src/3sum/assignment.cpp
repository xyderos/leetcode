#include "assignment.h"

#include <algorithm>

static auto
contains_permutation(std::vector<int> v1, std::set<std::vector<int>> &v) -> bool
{

	bool cond = false;

	std::for_each(v.begin(), v.end(), [&](std::vector<int> vec) {
		if (cond) {
			return;
		}
		if (std::is_permutation(vec.begin(), vec.end(), v1.begin(),
			v1.end())) {
			cond = true;
		}
	});

	return cond;
}

auto
three_sum(const std::vector<int> &array) -> std::set<std::vector<int>>
{
	std::set<std::vector<int>> result;

	for (uint i = 0; i < array.size(); i++) {
		for (uint j = 0; j < array.size(); j++) {
			for (uint k = 0; k < array.size(); k++) {
				std::vector<int> tmp { array.at(i), array.at(j),
					array.at(k) };

				if ((i != j && i != k && j != k) &&
				    (array.at(i) + array.at(j) + array.at(k) ==
					0) &&
				    !contains_permutation(tmp, result)) {
					result.insert({ array.at(i),
					    array.at(j), array.at(k) });
				}
			}
		}
	}
	return result;
}
