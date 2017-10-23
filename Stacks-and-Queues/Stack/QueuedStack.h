//
// Created by vladimir on 10/10/17.
//

#ifndef STACKS_AND_QUEUES_QUEUEDSTACK_H
#define STACKS_AND_QUEUES_QUEUEDSTACK_H

#include "../Stack/Stack.h"
#include "LinkedQueue.h"

template<typename T>
class QueuedStack : public Stack<T> {
    LinkedQueue<T> one;
    LinkedQueue<T> two;

    void moveOneToTwo() {
        while (!one.isEmpty()) {
            two.enqueue(one.dequeue());
        }
    }

    void moveTwoToOne() {
        while (!two.isEmpty()) {
            one.enqueue(two.dequeue());
        }
    }


public:
    T pop() override {
        if (isEmpty()) {
            throw std::logic_error("Stack is empty");
        }

        if (one.isEmpty()) {
            return two.dequeue();
        }

        return one.dequeue();
    }

    const T &peek() override {
        if (isEmpty()) {
            throw std::logic_error("Stack is empty");
        }

        if (one.isEmpty()) {
            return two.peek();
        }

        return one.peek();
    }

    void push(const T &data) override {
        if (one.isEmpty()) {
            one.enqueue(data);
            moveTwoToOne();
        } else {
            two.enqueue(data);
            moveOneToTwo();
        }
    }

    bool isEmpty() const override {
        return one.isEmpty() && two.isEmpty();
    }
};

#endif //STACKS_AND_QUEUES_QUEUEDSTACK_H
