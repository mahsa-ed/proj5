cmake_minimum_required(VERSION 3.29)
project(1st_phase C)

set(CMAKE_C_STANDARD 11)

add_executable(1st_phase main.c
        printColorMap.h
        actionsMenu.h
        war.h)

include_directories("C:\\MinGW\\include\\graphics")