cmake_minimum_required (VERSION 2.8.12)
project (Me)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++17" )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#-------------------------------------------------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeTools")
#-------------------------------------------------------------------------------
add_subdirectory(therdparty)
add_subdirectory(Services)
