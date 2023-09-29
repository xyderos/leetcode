#include "assignment.h"

#include <algorithm>
#include <iterator>
#include <map>

auto
group_anagrams(const std::vector<std::string> &v)
    -> std::vector<std::vector<std::string>>
{
	std::vector<std::string> cpy = v;
	auto result = std::vector<std::vector<std::string>>();

	// build similar keys
	std::for_each(cpy.begin(), cpy.end(),
	    [&](std::string &s) { std::sort(s.begin(), s.end()); });

	std::map<std::string, std::vector<int>> grid;

	// push them into a map with their corresponding positions in the
	// original vector
	for (auto x = cpy.begin(); x != cpy.end(); x++) {

		if (auto ptr = grid.find(*x); ptr != std::end(grid)) {
			ptr->second.emplace_back(std::distance(cpy.begin(), x));
		}

		else {
			grid.emplace(*x,
			    std::vector<int> { static_cast<int>(
				std::distance(cpy.begin(), x)) });
		}
	}

	// filter them out from the original vector
	std::for_each(grid.begin(), grid.end(),
	    [&](const std::pair<std::string, std::vector<int>> &pair) {
		    std::vector<std::string> anagrams;

		    std::for_each(pair.second.begin(), pair.second.end(),
			[&](int x) { anagrams.emplace_back(v.at(x)); });

		    result.emplace_back(anagrams);
	    });

	return result;
}
