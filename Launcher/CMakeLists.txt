project(Launcher)
#-------------------------------------------------------------------------------
file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#-------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
#-------------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} Logger)
#-------------------------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PUBLIC
                             "${CMAKE_CURRENT_BINARY_DIR}"
                             "${CMAKE_CURRENT_SOURCE_DIR}")
#-------------------------------------------------------------------------------
