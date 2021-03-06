//
// Created by vladimir on 10/10/17.
//

#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

template <typename T>
class Queue {
public:
    virtual T dequeue() = 0;
    virtual const T &peek() = 0;
    virtual void enqueue(const T &data) = 0;
    virtual bool isEmpty() const = 0;
};

#endif //STACK_QUEUE_H
