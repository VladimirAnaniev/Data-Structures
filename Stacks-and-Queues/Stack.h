//
// Created by vladimir on 09/10/17.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template <typename T>
class Stack {
public:
    virtual T pop() = 0;
    virtual const T &peek() = 0;
    virtual void push(const T &data) = 0;
    virtual bool isEmpty() const = 0;
};

#endif //STACK_STACK_H
