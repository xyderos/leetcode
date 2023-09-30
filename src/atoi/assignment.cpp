#include "assignment.h"

#include <cmath>
#include <limits>

static void
clear_leading_whitespace(std::string &s)
{
	auto it = s.begin();

	while (*it == ' ')
		s.erase(it);
}

static auto
is_positive(std::string &s) -> bool
{
	bool isPositive = true;
	if (*s.begin() == '+' || *s.begin() == '-') {
		isPositive = *s.begin() == '+' ? true : false;
		// delete it since we determined the sign
		s.erase(s.begin());
	}

	return isPositive;
}

static void
clear_trailing_characters(std::string &s)
{
	auto it = s.begin();

	while (!std::isdigit(*it)) {
		s.erase(it);
	}

	// until you find the next number, advance
	while (std::isdigit(*it)) {
		it++;
	}

	while (it != s.end()) {
		s.erase(it);
	}
}

static auto
determine_the_number(std::string &s) -> long long
{
	long long result = 0;

	uint pow_of_ten = 0;

	for (auto i = s.rbegin(); i != s.rend(); i++) {
		int digit = *i - 48;

		auto p = std::pow(10, pow_of_ten);

		result += (digit * p);

		pow_of_ten++;
	}

	return result;
}

auto
my_atoi(const std::string &s) -> int
{
	auto tmp = s;

	// clear leading whitespace
	clear_leading_whitespace(tmp);

	// determine sign
	bool positive = is_positive(tmp);

	// clear trailing characters
	clear_trailing_characters(tmp);

	// determine the number
	long long wrapped_result = determine_the_number(tmp);

	if (wrapped_result > std::numeric_limits<int>::max() ||
	    wrapped_result < std::numeric_limits<int>::min()) {
		return wrapped_result > std::numeric_limits<int>::max() ?
		    std::numeric_limits<int>::max() :
		    std::numeric_limits<int>::min();
	}

	// safe to return since with casting since we checked it will not
	// overflow the result
	return positive ? (int)wrapped_result : -(int)wrapped_result;
}
