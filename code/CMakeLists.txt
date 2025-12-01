add_executable(${PROJECT_NAME})

add_custom_target(run 
    COMMAND ${PROJECT_NAME}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
)

set(SOURCES
   main.cpp
   add.cpp
   mock_example.cpp
   external_discount.cpp
)
#message(STATUS "The value of SOURCES is: ${SOURCES}")

target_sources(${PROJECT_NAME}  PRIVATE ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/build"
                                                 RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/build")  