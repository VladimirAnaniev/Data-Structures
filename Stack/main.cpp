#include <iostream>
#include "LinkedStack.h"

void testInception() {
    LinkedStack<int> inner;
    inner.push(5);
    inner.push(42);

    LinkedStack<LinkedStack<int>> stack;
    stack.push(LinkedStack<int>());
    stack.push(inner);

    LinkedStack<LinkedStack<LinkedStack<int>>> outer; // Meta
    outer.push(LinkedStack<LinkedStack<int>>());
    outer.push(stack);

    LinkedStack<LinkedStack<int>> fromOuter = outer.pop();
    LinkedStack<int> fromFromOuter = fromOuter.pop();

    std::cout << fromFromOuter.pop() << " = 42" << std::endl;
    std::cout << fromFromOuter.pop() << " = 5" << std::endl;
}

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

int main() {
//    testInception();
    testPop();
    testPush();
    return 0;
}