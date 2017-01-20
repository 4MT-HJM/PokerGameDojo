PROJECT(PokerGame)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=c++14")
include_directories("googletest/googletest/include")
include_directories("googletest/googlemock/include")
include_directories("googletest/googletest")
include_directories("googletest/googlemock")
include_directories("inc")
add_library(gtestgmock googletest/googletest/src/gtest-all.cc googletest/googlemock/src/gmock-all.cc)


add_executable(PokerGameTest test_module/main.cpp test_module/hiker.tests.cpp src/hiker.cpp)
target_link_libraries(PokerGameTest gtestgmock pthread)
