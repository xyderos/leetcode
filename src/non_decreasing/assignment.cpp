#include <sys/types.h>

#include "assignment.h"

auto
non_decreasing(const std::vector<int> &v) -> bool
{
	uint anomalies = 0;

	for (auto i = v.begin(); i != v.end(); i++) {
		if (anomalies > 1) {
			return false;
		}

		if (i + 1 != v.end() && *i > *(i + 1)) {
			anomalies++;
		}
	}

	return true;
}
