cmake_minimum_required(VERSION 3.8)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack.h StackImpl.h)
add_executable(Stack ${SOURCE_FILES})