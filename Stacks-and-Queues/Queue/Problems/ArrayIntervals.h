//
// Created by vladimir on 06/11/17.
//

#ifndef STACKS_AND_QUEUES_ARRAYINTERVALS_H
#define STACKS_AND_QUEUES_ARRAYINTERVALS_H

#include <queue>


class ArrayIntervals {
    int *arr;
    int size;

    void printQueue(std::queue<int> queue);

public:
    ArrayIntervals(const int * arr, int size);
    ~ArrayIntervals();
    //TODO: BIG 4

    void printIntervals(int a, int b);


};


#endif //STACKS_AND_QUEUES_ARRAYINTERVALS_H
