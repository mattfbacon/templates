#include <array>
#include <fstream>
#include <iostream>

#include "AssertionFailure.hpp"
#include "Tests/tests.hpp"

std::string const TEST_INDENT = "  ";

char const* AssertionFailure::what() const noexcept {
	return "AssertionFailure";
}
void AssertionFailure::log(std::ostream& o) const noexcept {
	o << what() << " at " << file << ':' << line << ":\n";
	o << TEST_INDENT << assertion_string << '\n';
}

namespace ExitCode {
using exitcode_t = int;
constexpr exitcode_t success = 0;
constexpr exitcode_t internal_failure = 1;
constexpr exitcode_t test_failure = 2;
}  // namespace ExitCode

struct Test {
	char const* name;
	void (*run)(void) noexcept(false);
};

std::array<Test, 0> tests{
	// ex: Test{ "Name", Tests::name },
};

int main() {
	std::cout << "Starting tests" << std::endl;
	struct {
		size_t succeeded = 0, failed = 0, total = 0;
		bool exited_with_exception = false;
		float success_rate() {
			if (total == 0) {
				return 1.0;
			}
			return (float)succeeded / (float)total;
		}
	} stats;

	for (auto& test : tests) {
		bool succeeded = true;
		try {
			test.run();
		} catch (AssertionFailure const& e) {
			std::cout << TEST_INDENT << "× " << test.name << std::endl;
			e.log(std::cout);
			succeeded = false;
		} catch (std::exception const& e) {
			std::cout << TEST_INDENT << "! " << test.name << std::endl;
			std::cout << "An exception occurred in the test: " << e.what() << std::endl;
			stats.exited_with_exception = true;
			break;
		}
		if (succeeded) {
			stats.succeeded++;
			// if users want to only see failures, they can pipe stderr to /dev/null
			std::clog << TEST_INDENT << "✓ " << test.name << std::endl;
		} else {
			stats.failed++;
		}
		stats.total++;
	}

	std::cout << "Test summary:" << std::endl;
	if (stats.exited_with_exception) {
		std::cout << TEST_INDENT << "Note: exited with exception; the following statistics are as they were before the exception" << std::endl;
	}
	std::clog << TEST_INDENT << "Total: " << stats.total << std::endl;
	std::cout << TEST_INDENT << "Failed: " << stats.failed << std::endl;
	std::clog << TEST_INDENT << "Succeeded: " << stats.succeeded << std::endl;
	std::clog << (stats.success_rate() * 100) << "% success rate" << std::endl;
}
