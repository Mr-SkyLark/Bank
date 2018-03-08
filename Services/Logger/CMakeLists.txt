cmake_minimum_required(VERSION 2.8.12)  
#-------------------------------------------------------------------------------
project(Logger) 
#-------------------------------------------------------------------------------							
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}")
#-------------------------------------------------------------------------------
file(GLOB_RECURSE HEADERS 
      "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/*.h*")
file(GLOB_RECURSE SOURCES 
      "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
#-------------------------------------------------------------------------------
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
#-------------------------------------------------------------------------------
set_target_properties(${PROJECT_NAME}
                        PROPERTIES
                          DEBUG_POSTFIX "_d")
											
#-------------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
                             "${CMAKE_CURRENT_BINARY_DIR}/include"
                             "${CMAKE_CURRENT_SOURCE_DIR}/include")
#-------------------------------------------------------------------------------
