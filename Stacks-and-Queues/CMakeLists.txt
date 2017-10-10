cmake_minimum_required(VERSION 3.8)
project(Stacks-and-Queues)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack.h LinkedStack.h Queue.h LinkedQueue.h LinkedNode.h)
add_executable(Stacks-and-Queues ${SOURCE_FILES})