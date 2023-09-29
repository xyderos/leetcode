#include "assignment.h"

#include <algorithm>
#include <map>

auto
count_and_say(const std::vector<int> &container)
    -> std::vector<std::pair<int, int>>
{
	std::vector<std::pair<int, int>> result {};

	std::map<int, int> grid;

	std::for_each(container.begin(), container.end(), [&](int x) {
		if (auto ptr = grid.find(x); ptr != std::end(grid)) {
			ptr->second++;
		}

		else {
			grid.emplace(x, 1);
		}
	});

	std::for_each(grid.begin(), grid.end(),
	    [&](const std::pair<int, int> &pair) {
		    result.emplace_back(pair.first, pair.second);
	    });

	return result;
}
