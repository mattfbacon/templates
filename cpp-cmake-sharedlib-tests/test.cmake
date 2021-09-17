set(DIR_TEST test)

set(test_sources
	main.cpp
	Tests/fail.cpp
	Tests/succeed.cpp
	)
list(TRANSFORM test_sources PREPEND ${${PROJECT_NAME}_SOURCE_DIR}/${DIR_TEST}/)
add_executable(test ${test_sources})
target_include_directories(test PRIVATE ${${PROJECT_NAME}_SOURCE_DIR}/${DIR_TEST})
target_link_libraries(test PRIVATE ${${PROJECT_NAME}_SOURCE_DIR}/${DIR_DIST}/Debug/lib${EXECUTABLE_NAME}.so)
add_dependencies(test ${EXECUTABLE_NAME})

set_property(TARGET test PROPERTY RUNTIME_OUTPUT_DIRECTORY "${${PROJECT_NAME}_SOURCE_DIR}/${DIR_DIST}")
set_property(TARGET test PROPERTY LIBRARY_OUTPUT_DIRECTORY "${${PROJECT_NAME}_SOURCE_DIR}/${DIR_DIST}")
set_property(TARGET test PROPERTY ARCHIVE_OUTPUT_DIRECTORY "${${PROJECT_NAME}_SOURCE_DIR}/${DIR_DIST}")
