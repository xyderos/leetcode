#include "assignment.h"

#include <algorithm>

using std::map;

static map<char, std::vector<char>> table {
	{ '2', { 'a', 'b', 'c' } },
	{ '3', { 'd', 'e', 'f' } },
	{ '4', { 'g', 'h', 'i' } },
	{ '5', { 'k', 'l', 'm' } },
	{ '6', { 'n', 'o', 'p' } },
	{ '7', { 'p', 'q', 'r', 's' } },
	{ '8', { 't', 'u', 'v' } },
	{ '9', { 'w', 'x', 'y', 'z' } },
};

static auto
rank_up(const std::set<std::string> &accumulator, const std::vector<char> &v,
    int current_rank) -> std::set<std::string>
{
	std::set<std::string> new_accumulator;

	if (current_rank == 0) {
		std::for_each(v.begin(), v.end(),
		    [&](char c) { new_accumulator.insert(std::string { c }); });
	}

	else {
		std::for_each(accumulator.begin(), accumulator.end(),
		    [&](std::string p) {
			    std::for_each(v.begin(), v.end(), [&](char x) {
				    if ((p + x).length() >= current_rank) {
					    new_accumulator.insert(p + x);
				    }
			    });
		    });
	}

	return new_accumulator;
}

auto
combinations(const std::string &s) -> std::set<std::string>
{
	std::set<std::string> result;
	std::string cpy = s;

	int current_rank = 0;

	while (current_rank != cpy.length() + 1) {
		if (cpy.empty()) {
			break;
		}
		auto c = *cpy.begin();

		cpy.erase(cpy.begin());

		result = rank_up(result, table.at(c), current_rank);

		current_rank++;
	}

	return result;
}
