#include "assignment.h"

#include <algorithm>

static auto
flatten_list_of_words(const std::vector<std::string> &words) -> std::string
{
	std::string result;

	for (auto &&i : words) {
		result += i;
	}

	return result;
}

static auto
contains_permutation(const std::string &s, std::vector<std::string> words)
    -> bool
{
	if (flatten_list_of_words(words) == s) {
		return true;
	}

	if (words.size() == 2) {
		auto permutation = words[1] + words[0];

		return permutation == s ? true : false;
	}

	while (std::next_permutation(words.begin(), words.end())) {
		auto potential_permutation = flatten_list_of_words(words);

		if (potential_permutation == s) {
			return true;
		}
	}

	return false;
}

auto
concat_words(const std::string &s, std::vector<std::string> &words)
    -> std::vector<int>
{
	std::vector<int> result;

	int length_of_substring = 0;

	std::for_each(words.begin(), words.end(),
	    [&](const std::string &d) { length_of_substring += d.length(); });

	std::sort(words.begin(), words.end());

	int index = 0;
	while (index + length_of_substring <= s.length()) {
		auto subs = s.substr(index, length_of_substring);

		if (contains_permutation(subs, words)) {
			result.emplace_back(index);
		}

		index++;
	}

	return result;
}
