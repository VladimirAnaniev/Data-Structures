#include <iostream>
#include "StackImpl.h"

void testInception() {
    StackImpl<int> inner;
    inner.push(5);
    inner.push(42);

    StackImpl<StackImpl<int>> stack;
    stack.push(StackImpl<int>());
    stack.push(inner);

    StackImpl<StackImpl<StackImpl<int>>> outer; // Meta
    outer.push(StackImpl<StackImpl<int>>());
    outer.push(stack);

    StackImpl<StackImpl<int>> fromOuter = outer.pop();
    StackImpl<int> fromFromOuter = fromOuter.pop();

    std::cout << fromFromOuter.pop() << " = 42" << std::endl;
    std::cout << fromFromOuter.pop() << " = 5" << std::endl;
}

void testPop() {
    StackImpl<int> stack;
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
    StackImpl<int> stack;

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