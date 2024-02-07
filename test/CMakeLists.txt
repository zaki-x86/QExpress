# find_package(Qt5 COMPONENTS Test REQUIRED)
file(GLOB TEST_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

#target_link_libraries(server_unit_tests QExpress::Server Qt5::Core Qt5::Network Qt5::Test)

#
# Add the unit tests
#

foreach(TEST ${TEST_SRCS})
    # WARNING: this only works for CMake v3.14
    get_filename_component(TEST_NAME ${TEST} NAME_WLE)
    message(STATUS "Configured test: ${TEST_NAME}")

    add_executable(${TEST_NAME} ${TEST})
    set_target_properties(${TEST_NAME}
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )
    target_link_libraries(${TEST_NAME} QExpress::Server Qt5::Core Qt5::Network)
    target_include_directories(${TEST_NAME} PUBLIC ${DOCTEST_INCLUDE_DIR})
    doctest_discover_tests(${TEST_NAME} -v)
endforeach()

