#include "assignment.h"

#include <algorithm>
#include <sstream>
#include <string>

auto
reverse_integer(int s) -> int
{
	std::stringstream ss;

	ss << s;

	std::string res = ss.str();

	auto sign = res.at(0);

	if (sign == '-') {
		std::reverse(res.begin() + 1, res.end());
	} else {
		std::reverse(res.begin(), res.end());
	}

	return std::stoi(res);
}
