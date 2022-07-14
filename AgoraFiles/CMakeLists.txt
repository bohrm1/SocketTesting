#set version of cmake to version on server
cmake_minimum_required(VERSION "3.18.4")

set(CMAKE_CXX_FLAGS "-std=c++17")
#find_package(gflags REQUIRED)

#give project a name 
project(AgoraTest)

find_package(gflags REQUIRED)
message(STATUS "gflags include directory found: ${GFLAGS_INCLUDE_DIR}")

find_package(GTest REQUIRED)

add_executable(test_udp_client_server test_udp_client_server.cc udp_client.cc udp_server_ipv6.cc utils.cc)

target_link_libraries(test_udp_client_server gflags numa gtest)
