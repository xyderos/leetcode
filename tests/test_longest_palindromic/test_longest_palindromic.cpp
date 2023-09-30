#include <cppunit/TestAssert.h>

#include "../../src/longest_palindromic/assignment.h"
#include "test_longest_palindromic.h"

void
test_longest_palindromic::test_longest_palindromic_case_1()
{
	auto result = palindrome("babad");

	std::string expected("bab");

	CPPUNIT_ASSERT(expected == result);
}

void
test_longest_palindromic::test_longest_palindromic_case_2()
{
	auto result = palindrome("cbbd");

	std::string expected("bb");

	CPPUNIT_ASSERT(expected == result);
}
