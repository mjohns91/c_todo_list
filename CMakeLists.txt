cmake_minimum_required(VERSION 3.10)
project(c_todo_list C)

# Create a list of main application source files
set(MAIN_SOURCES
    src/main.c
    src/todo.c
    src/io.c
)

# Main application
add_executable(todo ${MAIN_SOURCES})

# Test executables
add_executable(test_todo 
    tests/test_todo.c
    src/todo.c
    src/io.c
)

add_executable(test_io 
    tests/test_io.c
    src/todo.c    # Include if test_io needs todo.c functions
    src/io.c
)