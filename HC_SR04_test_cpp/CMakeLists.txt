cmake_minimum_required(VERSION 3.18.4)

project(HC_SR04_proj)

find_library(wiringPi_lib wiringPi) # 라이브러리 'wiringPi'를 찾아 'wiringPi_lib'(var)에 저장

add_executable(HC_SR04_test main.cpp) # HC_SR04_test.exe 생성 / main.cpp를 포함(추가 가능)

target_link_libraries(HC_SR04_test ${wiringPi_lib}) # 'HC_SR04_test'에 '${wiringPi_lib}' link

set_target_properties(HC_SR04_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)