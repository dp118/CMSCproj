cmake_minimum_required(VERSION 3.17)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj1 driver.cpp buffer.h bufferlist.h buffer.cpp bufferlist.cpp )