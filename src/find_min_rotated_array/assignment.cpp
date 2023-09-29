#include "assignment.h"

auto
find_min(const std::vector<int> &v) -> int
{
	auto result = v.at(v.size() - 1);

	for (auto i = v.rbegin(); i != v.rend(); i++) {
		if (*i < result)
			result = *i;
	}

	return result;
}
