set(DIR_TEST test)

set(test_sources
	main.cpp
	)
list(TRANSFORM test_sources PREPEND ${DIR_TEST}/)

add_executable(tests ${test_sources})

find_package(Catch2 2 REQUIRED)
target_link_libraries(tests PRIVATE Catch2::Catch2 ${EXECUTABLE_NAME})
