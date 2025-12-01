# CppUTest should already be available from root CMakeLists.txt

# Create test executable
# Include the code under test (add.cpp, mock_example.cpp)
add_executable(${PROJECT_NAME}_tests
    test_add.cpp
    test_mock.cpp
    ${CMAKE_SOURCE_DIR}/code/add.cpp
    ${CMAKE_SOURCE_DIR}/code/mock_example.cpp
)

# Link against CppUTest libraries
# When using find_package, targets are CppUTest::CppUTest and CppUTest::CppUTestExt
# When using FetchContent, targets are CppUTest and CppUTestExt
if(TARGET CppUTest::CppUTest)
    # Using find_package - imported targets with namespace
    target_link_libraries(${PROJECT_NAME}_tests PRIVATE
        CppUTest::CppUTest
        CppUTest::CppUTestExt
    )
elseif(TARGET CppUTest)
    # Using FetchContent - regular targets without namespace
    target_link_libraries(${PROJECT_NAME}_tests PRIVATE
        CppUTest
        CppUTestExt
    )
else()
    message(FATAL_ERROR "CppUTest targets not found. Neither CppUTest::CppUTest nor CppUTest target exists.")
endif()

# Include directories
target_include_directories(${PROJECT_NAME}_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/code
)

# Add CppUTest include directories when using FetchContent
if(TARGET CppUTest AND NOT TARGET CppUTest::CppUTest)
    # Using FetchContent - need to add include directories manually
    get_target_property(CPPUTEST_INCLUDE_DIR CppUTest INTERFACE_INCLUDE_DIRECTORIES)
    if(CPPUTEST_INCLUDE_DIR)
        target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CPPUTEST_INCLUDE_DIR})
    else()
        # Fallback: try to find the include directory in the build directory
        target_include_directories(${PROJECT_NAME}_tests PRIVATE
            ${CMAKE_BINARY_DIR}/_deps/cpputest-src/include
        )
    endif()
endif()

# Set output directory - use CMAKE_BINARY_DIR for consistency
set_target_properties(${PROJECT_NAME}_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}"
)

# Register test with CTest (for ctest command)
# Use generator expression to ensure correct path resolution
add_test(NAME ${PROJECT_NAME}_tests COMMAND $<TARGET_FILE:${PROJECT_NAME}_tests>)

# Add POST_BUILD command to run tests after building the test executable
# This ensures tests run automatically after the executable is built
add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
    COMMAND $<TARGET_FILE:${PROJECT_NAME}_tests>
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    COMMENT "Running CppUTest tests"
    VERBATIM
)

# Add custom target to run tests (for explicit invocation)
add_custom_target(run_tests
    COMMAND $<TARGET_FILE:${PROJECT_NAME}_tests>
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    DEPENDS ${PROJECT_NAME}_tests
    COMMENT "Running CppUTest tests"
    VERBATIM
)

