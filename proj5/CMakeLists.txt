cmake_minimum_required(VERSION 3.17)
project(proj5)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj5 main.cpp Tqueue.cpp MediaPlayer.h Media.h Media.cpp MediaPlayer.cpp)