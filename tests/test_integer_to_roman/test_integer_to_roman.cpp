#include <cppunit/TestAssert.h>

#include "../../src/integer_to_roman/assignment.h"
#include "test_integer_to_roman.h"

void
test_integer_to_roman::test_roman_to_int_single_digit()
{
	auto result = int_to_roman(3);

	CPPUNIT_ASSERT("III" == result);
}

void
test_integer_to_roman::test_roman_to_int_two_digits()
{
	auto result = int_to_roman(58);

	CPPUNIT_ASSERT("LVIII" == result);
}

void
test_integer_to_roman::test_roman_to_int_three_digits()
{
	auto result = int_to_roman(582);

	CPPUNIT_ASSERT("DLXXXII" == result);
}

void
test_integer_to_roman::test_roman_to_int_four_digits()
{
	auto result = int_to_roman(1994);

	CPPUNIT_ASSERT("MCMXCIV" == result);
}
