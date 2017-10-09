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
class StackImpl : public Stack<T> {
    Element<T> *head;

public:

    StackImpl(): head(nullptr) {}
    ~StackImpl() {
        if(!isEmpty()) {
            head->destroy();
            delete head;
        }
    }

    const T &pop() override {
        if(!isEmpty()) {
            Element<T> *removed = head;
            head = head->next;
            return removed->data;
        }

        throw std::logic_error("Stack is empty");
    }

    const T &peek() const override {
        if(!isEmpty()) {
            return head->data;
        }

        throw std::logic_error("Stack is empty");
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
