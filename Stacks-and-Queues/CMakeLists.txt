cmake_minimum_required(VERSION 3.8)
project(Stacks-and-Queues)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack/Stack.h Stack/LinkedStack.h Queue/Queue.h Queue/LinkedQueue.h LinkedNode.h Queue/StackedQueue.h Stack/QueuedStack.h Queue/PriorityQueue.h Stack/Problems/Decompressor.cpp Stack/Problems/Decompressor.h Queue/Problems/Sequence.cpp Queue/Problems/Sequence.h Queue/Problems/ArrayIntervals.cpp Queue/Problems/ArrayIntervals.h)
add_executable(Stacks-and-Queues ${SOURCE_FILES})