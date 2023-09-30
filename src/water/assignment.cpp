#include "assignment.h"

#include <iterator>
#include <vector>

static inline auto
min(int a, int b) -> int
{
	return a < b ? a : b;
}

auto
water(const std::vector<int> &array) -> int
{
	int res = 0;

	for (auto i = array.begin(); i != array.end(); i = std::next(i)) {
		for (auto j = i; j != array.end(); j = std::next(j)) {
			int dst = std::distance(i, j);

			if (dst == 0) {
				continue;
			}

			int area = min(*i, *j) * dst;

			if (area > res) {
				res = area;
			}
		}
	}

	return res;
}