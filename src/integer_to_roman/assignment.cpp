#include "assignment.h"

#include <sstream>
#include <vector>

static const std::vector<std::pair<int, std::string>> FACTORS { { 1000, "M" },
	{ 500, "D" }, { 100, "C" }, { 50, "L" }, { 10, "X" }, { 5, "V" },
	{ 1, "I" } };

auto
int_to_roman(int n) -> std::string
{
	std::stringstream ss;

	auto it = FACTORS.begin();

	while (n != 0) {
		if (n - (*it).first < 0) {
			it++;
			continue;
		}

		if (0 < (n - 900) && (n - 900) < 100) {
			n -= 900;
			ss << "CM";
			continue;
		}

		if (0 < (n - 400) && (n - 400) < 100) {
			n -= 400;
			ss << "CD";
			continue;
		}

		if (0 < (n - 90) && (n - 90) < 10) {
			n -= 90;
			ss << "XC";
			continue;
		}

		if (0 < (n - 40) && (n - 40) < 10) {
			n -= 40;
			ss << "XL";
			continue;
		}

		if (n - 9 == 0) {
			n -= 9;
			ss << "IX";
			continue;
		}

		if (n - 4 == 0) {
			n -= 4;
			ss << "IV";
			continue;
		}

		ss << (*it).second;
		n -= (*it).first;
	}

	return ss.str();
}