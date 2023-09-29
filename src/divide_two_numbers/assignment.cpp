#include <sys/types.h>

#include "assignment.h"

static auto
determine_sign(int either, int other) -> int
{
	return ((either > 0) - (either < 0)) ^ ((other > 0) - (other < 0));
}

static auto
clear_signs(int n) -> uint
{
	return n > 0 ? n : (uint)-n;
}

auto
divide(int dividend, int divisor) -> int
{
	uint d1 = clear_signs(dividend), d2 = clear_signs(divisor);

	auto res = 0;

	while ((int)(d1 - d2) >= 0) {
		res++;
		d1 -= d2;
	}

	return determine_sign(dividend, divisor) == 0 ? res : -res;
}