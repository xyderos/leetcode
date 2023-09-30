#include <cppunit/TestAssert.h>

#include "../../src/match/assignment.h"
#include "test_match.h"

void
test_match::first_test()
{
	CPPUNIT_ASSERT(!match("aa", "a"));
}

void
test_match::second_test()
{
	CPPUNIT_ASSERT(match("aa", "a*"));
}

void
test_match::third_test()
{
	CPPUNIT_ASSERT(match("ab", ".*"));
}
