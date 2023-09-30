#include "assignment.h"

#include <algorithm>

auto
rotate(const std::vector<std::vector<int>> &matrix)
    -> std::vector<std::vector<int>>
{
	std::vector<std::vector<int>> result(matrix.size(),
	    std::vector<int>(matrix.at(0).size()));

	auto index = matrix.size() - 1;
	std::for_each(matrix.begin(), matrix.end(),
	    [&](const std::vector<int> &c) {
		    auto idx = 0;
		    std::for_each(c.begin(), c.end(), [&](int num) {
			    result[idx][index] = num;
			    idx++;
		    });

		    index--;
	    });

	return result;
}
