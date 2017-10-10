//
// Created by vladimir on 10/10/17.
//

#ifndef STACK_LINKEDELEMENT_H
#define STACK_LINKEDELEMENT_H

template <typename T>
struct LinkedNode {
    T data;
    LinkedNode *next;

    LinkedNode(): data(T()), next(nullptr) {}

    void destroy() {
        if(next != nullptr) {
            next->destroy();
        }

        delete next;
    }
};

#endif //STACK_LINKEDELEMENT_H
