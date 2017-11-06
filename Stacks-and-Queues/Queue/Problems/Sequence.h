//
// Created by vladimir on 06/11/17.
//

#ifndef STACKS_AND_QUEUES_SEQUENCE_H
#define STACKS_AND_QUEUES_SEQUENCE_H


#include <queue>

class Sequence {
    std::queue<int> sequence;
    int index;

    void generate(int maxIndex);

    void push(int elem);

public:
    explicit Sequence(int initial);

    int getElement(int index);
};


#endif //STACKS_AND_QUEUES_SEQUENCE_H
