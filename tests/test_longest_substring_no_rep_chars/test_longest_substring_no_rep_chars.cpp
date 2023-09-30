#include <cppunit/TestAssert.h>

#include "../../src/longest_substring_no_rep_chars/assignment.h"
#include "test_longest_substring_no_rep_chars.h"

void
test_longest_substring_no_rep_chars::test_longest_sub_no_reps_simple()
{
	auto result = length("abcabcbb");

	CPPUNIT_ASSERT_EQUAL(3, result);
}

void
test_longest_substring_no_rep_chars::test_longest_sub_no_reps_simple_also()
{
	auto result = length("bbbbb");

	CPPUNIT_ASSERT_EQUAL(1, result);
}

void
test_longest_substring_no_rep_chars::test_longest_sub_no_reps_sequence()
{
	auto result = length("pwwkew");

	CPPUNIT_ASSERT_EQUAL(3, result);
}
