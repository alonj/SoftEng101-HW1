cmake_minimum_required(VERSION 3.9)
project(hw1AttachedCodeFiles)

set(CMAKE_CXX_STANDARD 98)

add_executable(hw1AttachedCodeFiles
        Interface.h
        main.cpp
        Map.cpp
        Map.h
        Printer.h
        Interface.cpp RobotDB.cpp RobotDB.h)
