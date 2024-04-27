cmake_minimum_required(VERSION 3.27)
project(BugsLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(BugsLife main.cpp
        classes/Bug.cpp
        classes/Bug.h
        classes/Crawler.cpp
        classes/Crawler.h
        classes/Hopper.cpp
        classes/Hopper.h
        classes/Board.cpp
        classes/Board.h
        classes/Drifter.cpp)
