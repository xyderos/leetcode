#include "assignment.h"

#include <algorithm>

auto
palindrome(const std::string &s) -> std::string
{
	std::string palindrome = "";

	for (size_t i = 0; i < s.length(); i++) {
		for (size_t j = i; j < s.length(); j++) {
			std::string potential_palindrome = s.substr(i, j);

			std::string tmp(potential_palindrome);

			std::reverse(tmp.begin(), tmp.end());

			if (potential_palindrome == tmp &&
			    std::distance(tmp.begin(), tmp.end()) > 1) {
				if (potential_palindrome.length() >
				    palindrome.length()) {
					palindrome = potential_palindrome;
				}
			}
		}
	}

	return palindrome;
}
