#include <cppunit/TestAssert.h>

#include "../../src/substring_with_concat_of_all_words/assignment.h"
#include "test_substring_with_concat_of_all_words.h"

#include <vector>

void
test_substring_with_concat_of_all_words::test_concat_substring_case_1()
{
	std::vector<std::string> words { "foo", "bar" };
	auto result = concat_words("barfoothefoobarman", words);

	std::vector<int> expected { 0, 9 };

	CPPUNIT_ASSERT(result == expected);
}

void
test_substring_with_concat_of_all_words::test_concat_substring_case_2()
{
	std::vector<std::string> words { "word", "good", "best", "word" };
	auto result = concat_words("wordgoodgoodgoodbestword", words);

	std::vector<int> expected {};

	CPPUNIT_ASSERT(result == expected);
}

void
test_substring_with_concat_of_all_words::test_concat_substring_case_3()
{
	std::vector<std::string> words { "bar", "foo", "the" };
	auto result = concat_words("barfoofoobarthefoobarman", words);

	std::vector<int> expected { 6, 9, 12 };

	CPPUNIT_ASSERT(result == expected);
}
