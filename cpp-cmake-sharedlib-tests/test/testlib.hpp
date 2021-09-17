#pragma once

#include "AssertionFailure.hpp"

#define TESTLIB_ASSERT(cond) \
	if (!(cond)) { \
		throw AssertionFailure{ #cond, __LINE__, __FILE__ }; \
	}
