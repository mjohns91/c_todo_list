cmake_minimum_required(VERSION 3.31)
project(c_todo_list C)

set(CMAKE_C_STANDARD 11)

add_executable(c_todo_list main.c
        io.h
        todo.h
        io.c)
