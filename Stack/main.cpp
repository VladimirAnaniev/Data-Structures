#include <iostream>
#include "StackImpl.h"

int main() {
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

    return 0;
}