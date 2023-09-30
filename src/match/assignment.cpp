#include "assignment.h"

#include <sstream>
#include <vector>

static auto
split(const std::string &s) -> std::vector<std::string>
{
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string accumulator;

	while (std::getline(ss, accumulator)) {
		std::size_t prev = 0, pos = 0;
		while ((pos = accumulator.find_first_of(". *", prev)) !=
		    std::string::npos) {
			if (pos > prev) {

				result.push_back(
				    accumulator.substr(prev, pos - prev));

				if (accumulator.at(pos) == '*') {
					result.emplace_back("*");
				} else {
					result.emplace_back(".");
				}
			}
			prev = pos + 1;
		}
		if (prev < accumulator.length()) {
			result.push_back(
			    accumulator.substr(prev, std::string::npos));
		}
	}

	return result;
}

auto
match(const std::string &s, const std::string &p) -> bool
{
	// get all the sub patterns from the input and start iterating over the
	// original string
	std::vector<std::string> tokens = split(p);

	unsigned int i = 0;

	while (!tokens.empty()) {
		auto token = tokens.front();

		// match the case where the token is *
		if (token == "*") {
			tokens.erase(std::begin(tokens));

			if (!tokens.empty()) {
				auto tmp = tokens.front();

				while (i < s.length() && (s[i] != tmp.at(0))) {
					i++;
				}
			} else {
				return true;
			}
		}
		// match the case where token is .
		else if (token == ".") {
			tokens.erase(std::begin(tokens));

			if (!tokens.empty()) {
				if (i < s.length()) {
					i++;
				}
			} else {
				return true;
			}

		}
		// match the case where the token represents a word
		else {
			tokens.erase(std::begin(tokens));

			auto length = token.length();
			auto substring = s.substr(i, length);

			if (substring == token) {
				i += length;

			} else {
				return false;
			}

			if (tokens.size() == 0 && s.length() > 0) {
				return false;
			}
		}
	}
	return true;
}
