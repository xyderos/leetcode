#include "assignment.h"

#include <algorithm>
#include <vector>

static auto
contains(const std::string &s, char c) -> bool
{
	for (auto &&i : s) {
		if (i == c) {
			return true;
		}
	}

	return false;
}

auto
length(const std::string &s) -> int
{
	std::vector<int> container;

	for (size_t i = 0; i < s.length(); i++) {
		std::string potential_string;

		potential_string.push_back(s.at(i));

		for (size_t j = i; j < s.length(); j++) {
			if (j + 1 == s.length()) {
				potential_string.clear();
				break;
			}

			if (contains(potential_string, s.at(j + 1))) {
				container.emplace_back(
				    potential_string.length());
				potential_string.clear();

				break;
			}

			potential_string.push_back(s.at(j + 1));
		}
	}

	return *std::max_element(container.begin(), container.end());
}
