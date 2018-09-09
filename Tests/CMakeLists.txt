cmake_minimum_required(VERSION 2.8.12)

project(Tests)

set (GTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gtest/include")

message(" AAAAAAAAAAAAAAAAAAA - ${GTEST_INCLUDE_DIR}")
enable_testing()
find_package(Gtest REQUIRED)
find_package(Threads REQUIRED)

include_directories("${GTEST_INCLUDE_DIR}")

add_executable(${PROJECT_NAME}
    mainTests.cpp
)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG})

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
