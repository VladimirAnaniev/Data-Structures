//
// Created by vladimir on 11/10/17.
//

#include <iostream>
#include "../LinkedStack.h"

void pushSorted(Stack<int> &stack, int elem) {
    LinkedStack<int> temp;

    while(!stack.isEmpty() && stack.peek() < elem) {
        temp.push(stack.pop());
    }

    stack.push(elem);

    while(!temp.isEmpty()) {
        stack.push(temp.pop());
    }
}

void pushSortedRec(Stack<int> &stack, int num) {
    if(stack.isEmpty() || stack.peek() >= num) {
        stack.push(num);
        return;
    }

    int top = stack.pop();

    pushSortedRec(stack, num);

    stack.push(top);
}

void sortStack(Stack<int> &stack) {
    if(stack.isEmpty()) {
        return;
    }

    int top = stack.pop();

    sortStack(stack);

    pushSortedRec(stack, top);
}

void testSortStack() {
    LinkedStack<int> stack;

    stack.push(1);
    stack.push(8);
    stack.push(5);
    stack.push(3);
    stack.push(10);
    stack.push(7);

    sortStack(stack);

    while(!stack.isEmpty()) {
        std::cout<<stack.pop()<<", ";
    }
}