//
// Created by vladimir on 09/10/17.
//

#ifndef STACK_STACKIMPL_H
#define STACK_STACKIMPL_H


#include "Stack.h"

template <typename T>
struct Element {
    T data;
    Element *next;

    Element(): data(T()), next(nullptr) {}

    void destroy() {
        if(next != nullptr) {
            next->destroy();
        }

        delete next;
    }
};

template <typename T>
class LinkedStack : public Stack<T> {
    Element<T> *head;

public:

    LinkedStack(): head(nullptr) {}
    ~LinkedStack() {
        if(!isEmpty()) {
            head->destroy();
            delete head;
        }
    }

    const T &pop() override {
        if(isEmpty()) {
            throw std::logic_error("Stack is empty");
        }

        Element<T> *removed = head;
        head = head->next;
        return removed->data;
    }

    const T &peek() const override {
        if(!isEmpty()) {
            throw std::logic_error("Stack is empty");
        }

        return head->data;
    }

    void push(const T &data) override {
        auto *newElem = new Element<T>();
        newElem->data = data;
        newElem->next = head;
        head = newElem;
    }

    bool isEmpty() const override {
        return head == NULL;
    }
};


#endif //STACK_STACKIMPL_H
