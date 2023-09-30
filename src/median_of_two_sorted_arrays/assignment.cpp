#include "assignment.h"

#include <algorithm>

static auto
merge(const std::vector<int> &v1, const std::vector<int> &v2)
    -> std::vector<int>
{
	std::vector<int> result;

	for (auto it1 = v1.begin(), it2 = v2.begin();
	     (it1 != v1.end()) && (it2 != v2.end());) {
		if (*it1 < *it2 && it1 != v1.end()) {
			result.push_back(*it1);

			it1++;

			if (it1 == v1.end()) {
				std::for_each(it2, v2.end(),
				    [&](int x) { result.push_back(x); });

				it2 = v2.end();
				break;
			}

			continue;
		}

		else if (*it1 > *it2 && it2 != v2.end()) {
			result.push_back(*it2);

			it2++;

			if (it2 == v2.end()) {
				std::for_each(it1, v1.end(),
				    [&](int x) { result.push_back(x); });

				it1 = v1.end();
				break;
			}

			continue;
		}
	}

	return result;
}

auto
median(const std::vector<int> &v1, const std::vector<int> &v2) -> double
{
	std::vector<int> res = merge(v1, v2);

	return res.size() % 2 == 0 ?
	    (double)(res.at(res.size() / 2 - 1) + res.at((res.size() / 2))) /
		2.0 :
	    res.at(res.size() / 2);
}
