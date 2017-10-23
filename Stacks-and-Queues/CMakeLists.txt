cmake_minimum_required(VERSION 3.8)
project(Stacks-and-Queues)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack/Stack.h Stack/LinkedStack.h Queue/Queue.h Queue/LinkedQueue.h LinkedNode.h Queue/StackedQueue.h Stack/QueuedStack.h Queue/PriorityQueue.h)
add_executable(Stacks-and-Queues ${SOURCE_FILES})