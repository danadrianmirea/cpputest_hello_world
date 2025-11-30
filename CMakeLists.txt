set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_VERBOSE_MAKEFILE ON)

cmake_minimum_required(VERSION 3.28)

project(cpputest_hello_world)

# Enable testing
enable_testing()

# Find CppUTest - try find_package first, fallback to FetchContent
find_package(CppUTest QUIET)

if(NOT CppUTest_FOUND)
    message(STATUS "CppUTest not found via find_package, using FetchContent to download it")
    include(FetchContent)
    FetchContent_Declare(
        CppUTest
        GIT_REPOSITORY https://github.com/cpputest/cpputest.git
        GIT_TAG        v4.0
    )
    FetchContent_MakeAvailable(CppUTest)
endif()

add_subdirectory(code)
add_subdirectory(code/tests)

# Make the main executable depend on the test executable
# The POST_BUILD command on the test executable will run tests automatically
# and the build will fail if tests fail
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_tests)