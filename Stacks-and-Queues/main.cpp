#include <iostream>
#include "Stack/LinkedStack.h"
#include "Queue/LinkedQueue.h"
#include "Stack/StackedQueue.h"
#include "Queue/QueuedStack.h"

void testPop() {
    LinkedStack<int> stack;
    stack.push(2);

    try {
        std::cout << stack.pop() << std::endl;
        std::cout << stack.isEmpty() << " = 1" << std::endl;
        std::cout << stack.pop() << std::endl; //Should throw error
    }
    catch (std::logic_error &err) {
        std::cerr << err.what() << std::endl;
    }
}

void testPush() {
    QueuedStack<int> stack;

    for (int i = 0; i <= 100; i++) {
        stack.push(i);
    }

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << ", ";
    }
}

void testStack() {
    std::cout << "************TESTING STACK*************" << std::endl;
    testPop();
    testPush();
}

void testQueue() {
    std::cout << "************TESTING QUEUE*************" << std::endl;
    StackedQueue<int> queue;

    queue.enqueue(5);
    queue.enqueue(42);

    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << std::endl;
    }
}

int main() {
    testStack();
//    testQueue();
    return 0;
}