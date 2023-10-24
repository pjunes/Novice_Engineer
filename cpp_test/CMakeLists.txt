cmake_minimum_required(VERSION 3.10)

project(cpp_test) 
# project 명 설정 (일단 별 의미 없어 보임.)
# project 명을 설정하면 같은 이름으로 솔루션 파일 생성.

find_library(wiringPi_lib wiringPi)

add_executable(cpp_test cpp_test.cpp) # cpp file -> .exe / cpp_test가 파일명이 됨.
# add_executable(cpp_test cpp_test.cpp scr/cpp_test2.cpp) # cpp file -> .exe / cpp_test가 파일명이 됨.

target_link_libraries(cpp_test ${wiringPi_lib}) # 'cpp_test'에 '${}' link

set_target_properties(cpp_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)