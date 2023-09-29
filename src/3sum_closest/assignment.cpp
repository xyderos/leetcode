#include "assignment.h"

#include <algorithm>
#include <limits>

auto
quantrant(const std::vector<int> &array, int approx) -> int
{
	int delta = std::numeric_limits<int>::max();

	for (uint i = 0; i < array.size(); i++) {
		for (uint j = 0; j < array.size(); j++) {
			for (uint k = 0; k < array.size(); k++) {
				auto sum = array.at(k) + array.at(j) +
				    array.at(i);

				if ((i != j && i != k && j != k) &&
				    std::abs(approx - sum) < std::abs(delta)) {
					delta = sum;
				}
			}
		}
	}

	return delta;
}
