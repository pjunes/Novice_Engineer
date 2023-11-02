cmake_minimum_required(VERSION 3.18.4)

project(Network_Socket)

add_executable(Network_Socket_test main.cpp)

set_target_properties(Network_Socket_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)