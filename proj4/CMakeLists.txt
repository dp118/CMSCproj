cmake_minimum_required(VERSION 3.17)
project(proj4)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj4 main.cpp Zombie.h Sunflower.h Room.h Plant.h Peashooter.h Imp.h Game.h Entity.h Engineer.h Chomper.h Buckethead.h Game.cpp Entity.cpp Plants.cpp Zombies.cpp Room.cpp)