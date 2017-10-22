//
// Created by vladimir on 22/10/17.
//

#include <iostream>
#include "../Stack.h"
#include "../LinkedStack.h"

void move(Stack<int>& from, Stack<int>& spare, Stack<int>& to, int n) {
    if(n == 0) {
        return;
    }

    move(from, to, spare, n-1);
    to.push(from.pop());
    move(spare, from, to, n-1);
}

void testTowerOfHanoi(int n) {
    LinkedStack<int> start;
    LinkedStack<int> middle;
    LinkedStack<int> end;

    for (int i = n; i >= 1; i--) {
        start.push(i);
    }

    move(start, middle, end, n);

    while(!end.isEmpty()) {
        std::cout<<end.pop()<<", ";
    }
}

