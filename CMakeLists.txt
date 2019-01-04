cmake_minimum_required(VERSION 3.10...3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Jerboa  VERSION 0.1
                DESCRIPTION "A component graph system"
                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# library
add_library(jerboa INTERFACE)
target_include_directories(jerboa INTERFACE include/)
install(DIRECTORY include/ DESTINATION include)

# uninstall library
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

# examples
add_executable(example_spaceships src/examples/spaceships/main.cpp)
target_link_libraries(example_spaceships jerboa)

# tests
include(CTest)
enable_testing()

find_package(GTest)
if(GTest_FOUND)
    include(GoogleTest)

    add_executable(tests src/tests/main.cpp)
    target_link_libraries(tests jerboa gtest)

    gtest_discover_tests(tests)
endif()


# benchmarks
find_package(benchmark)
if(benchmark_FOUND)
    add_executable(benches src/benches/main.cpp)
    target_link_libraries(benches jerboa benchmark)
    add_test(benchmarks bin/benches)
endif()
