//
// Created by vladimir on 09/10/17.
//

#ifndef STACK_STACKIMPL_H
#define STACK_STACKIMPL_H


#include "Stack.h"
#include "../LinkedNode.h"

template <typename T>
class LinkedStack : public Stack<T> {
    LinkedNode<T> *head;

public:

    LinkedStack(): head(nullptr) {}
    ~LinkedStack() {
        if(!isEmpty()) {
            head->destroy();
            delete head;
        }
    }

    T pop() override {
        if(isEmpty()) {
            throw std::logic_error("Stack is empty");
        }

        LinkedNode<T> *removed = head;
        head = head->next;

        T data = removed->data;
        delete removed;

        return data;
    }

    const T &peek() override {
        if(!isEmpty()) {
            throw std::logic_error("Stack is empty");
        }

        return head->data;
    }

    void push(const T &data) override {
        auto *newElem = new LinkedNode<T>();
        newElem->data = data;
        newElem->next = head;
        head = newElem;
    }

    bool isEmpty() const override {
        return head == nullptr;
    }
};


#endif //STACK_STACKIMPL_H
