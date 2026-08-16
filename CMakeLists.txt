cmake_minimum_required(VERSION 3.10)
project(TrtitoneElectronics-Test-Assignment)
set(CMAKE_CXX_STANDARD 20)

add_library(
    tritoneelectroniks-test-assignment src/library.cpp
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    unit_test tests/unit_test.cpp
)
target_link_libraries(
    unit_test
    tritoneelectroniks-test-assignment
    GTest::gtest_main
)
target_include_directories(
    unit_test
    PUBLIC src
)
include(GoogleTest)
gtest_discover_tests(unit_test)
