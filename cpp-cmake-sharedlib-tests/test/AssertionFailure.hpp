#pragma once

#include <ostream>
#include <stdexcept>

struct AssertionFailure : public std::exception {
	AssertionFailure(char const* const assertion_string, size_t line, char const* const file) : assertion_string(assertion_string), line(line), file(file) {}
	char const* assertion_string;
	size_t line;
	char const* file;
	char const* what() const noexcept override;

	void log(std::ostream& o) const noexcept;
};
