//
// Created by vladimir on 27/10/17.
//
#include <string>
#include <stack>

std::string toBinary(int number) {
    std::stack<int> stack;

    while(number != 0) {
        stack.push(number % 2);
        number /= 2;
    }

    std::string result;

    while(!stack.empty()) {
        result += std::to_string(stack.top());
        stack.pop();
    }

    return result;
}
