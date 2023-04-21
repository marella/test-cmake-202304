cmake_minimum_required (VERSION 3.0)
project(test VERSION 0.1.0)

add_executable(main main.cc)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -mfma -mf16c -mavx -mavx2")
