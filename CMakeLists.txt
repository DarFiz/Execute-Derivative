cmake_minimum_required(VERSION 2.8.12.2)
project(ExecuteDerivative)

# SET( CMAKE_CXX_COMPILER "/usr/bin/g++-5" )
# SET( CMAKE_CXX_COMPILER "/usr/bin/clang++-3.5" )
set(GMOCK_DIR ./lib/gmock-1.7.0/)
set(GTEST_DIR ./lib/gmock-1.7.0/gtest)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O3 -std=c++11 -pthread")

#main
file(GLOB SOURCES "src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(main ${SOURCES})
target_include_directories(main PUBLIC ./include)

#tests
file(GLOB TEST_SOURCES "src/*.cpp" "test/*.cpp")
file(GLOB TO_REMOVE "src/main.cpp")
list(REMOVE_ITEM TEST_SOURCES ${TO_REMOVE})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(tests ${TEST_SOURCES})
target_include_directories(tests PUBLIC  ${GTEST_DIR}/include ${GMOCK_DIR}/include)
target_include_directories(tests PUBLIC ./include)
target_link_libraries(tests libgmock.a)

#GTest and GMock Lib generation
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_library(gmock STATIC ${GTEST_DIR}/src/gtest-all.cc ${GMOCK_DIR}/src/gmock-all.cc)
target_include_directories(gmock PUBLIC ${GMOCK_DIR}/include ${GMOCK_DIR}  ${GTEST_DIR}/include ${GTEST_DIR})