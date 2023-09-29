#include "assignment.h"

#include <algorithm>
#include <iterator>

auto
find_positions(const std::vector<int> &container, int n)
    -> std::pair<uint, uint>
{
	if (container.empty()) {
		return { -1, -1 };
	}

	std::vector<int> result {};

	if (auto i = std::find(container.begin(), container.end(), n);
	    i != std::end(container)) {
		return {
			std::distance(container.begin(), i),
			std::distance(container.begin(), i + 1),
		};
	}

	return { -1, -1 };
}
