cmake_minimum_required(VERSION 2.8.12)

project(Tests)

set (GTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gtest/include")
file(GLOB_RECURSE TESTS "${CMAKE_CURRENT_SOURCE_DIR}/*Tests.h*")

enable_testing()
find_package(Gtest REQUIRED)
find_package(Threads REQUIRED)

include_directories("${GTEST_INCLUDE_DIR}")

add_executable(${PROJECT_NAME}
    mainTests.cpp
    ${TESTS}
)

target_link_libraries(${PROJECT_NAME}
  ${GTEST_LIBRARY_DEBUG}
  ${GTEST_MAIN_LIBRARY_DEBUG}
  BaseLibrary)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
