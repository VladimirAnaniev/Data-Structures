//
// Created by vladimir on 10/10/17.
//

#ifndef STACK_LINKEDQUEUE_H
#define STACK_LINKEDQUEUE_H

#include <stdexcept>
#include "Queue.h"
#include "LinkedNode.h"

template <typename T>
class LinkedQueue : public Queue<T> {
    LinkedNode<T> *first;
    LinkedNode<T> *last;

public:
    LinkedQueue(): first(nullptr), last(nullptr) {}
    ~LinkedQueue() {
        if(!isEmpty()) {
            first->destroy();
            delete first;
        }
    }

    T dequeue() override {
        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        LinkedNode<T> *removed = first;
        first = first->next;

        T data = removed->data;
        delete removed;

        return data;
    }

    const T &peek() override {
        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        return first->data;
    }

    void enqueue(const T &data) override {
        auto *newElem = new LinkedNode<T>();
        newElem->data = data;
        newElem->next = nullptr;

        if(isEmpty()) {
            first = newElem;
        } else {
            last->next = newElem;
        }

        last = newElem;
    }

    bool isEmpty() const override {
        return first == nullptr;
    }

};

#endif //STACK_LINKEDQUEUE_H
