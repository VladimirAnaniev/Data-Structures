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
};

template <typename T>
class StackImpl : public Stack<T> {
    Element<T> *head;

public:

    const T &pop() override {
        Element<T> *removed = head;
        head = head->next;
        return removed->data;
    }

    const T &peek() const override {
        return head->data;
    }

    void push(const T &data) override {
        auto *newElem = new Element<T>();
        newElem->data = data;
        newElem->next = head;
        head = newElem;
    }

};


#endif //STACK_STACKIMPL_H
