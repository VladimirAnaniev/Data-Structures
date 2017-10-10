//
// Created by vladimir on 10/10/17.
//

#ifndef STACKS_AND_QUEUES_STACKEDQUEUE_H
#define STACKS_AND_QUEUES_STACKEDQUEUE_H

#include <stdexcept>
#include "Queue.h"
#include "LinkedStack.h"

template <typename T>
class StackedQueue : Queue<T> {
    LinkedStack<T> in;
    LinkedStack<T> out;

    void moveToOut() {
        while(!in.isEmpty()) {
            out.push(in.pop());
        }
    }

public:
    T dequeue() override {
        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        if(out.isEmpty()) {
            moveToOut();
        }

        return out.pop();
    }

    const T &peek() override {
        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        if(out.isEmpty()) {
            moveToOut();
        }

        return out.peek();
    }

    void enqueue(const T &data) override {
        in.push(data);
    }

    bool isEmpty() const override {
        return in.isEmpty() && out.isEmpty();
    }
};

#endif //STACKS_AND_QUEUES_STACKEDQUEUE_H
