cmake_minimum_required(VERSION 3.25)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    header.h
    main.cpp
    addition.cpp
    change.cpp
    input.cpp
    inputsCheck.cpp
    output.cpp
    removal.cpp
    sort.cpp
    text.cpp
    options.cpp
    view.cpp)