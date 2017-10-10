#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"

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
    LinkedStack<int> stack;

    for (int i = 0; i <= 100000; i++) {
        stack.push(i);
    }

    std::cout << stack.pop() << " = 100000" << std::endl;
}

void testStack() {
    std::cout<<"************TESTING STACK*************"<<std::endl;
    testPop();
    testPush();
}

void testQueue() {
    std::cout<<"************TESTING QUEUE*************"<<std::endl;
    LinkedQueue<int> queue;

    queue.add(5);
    queue.add(42);

    while (!queue.isEmpty()) {
        std::cout << queue.remove() << std::endl;
    }
}

int main() {
    testStack();
    testQueue();
    return 0;
}