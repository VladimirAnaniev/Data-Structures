//
// Created by vladimir on 06/11/17.
//

#include <queue>
#include <iostream>
#include "ArrayIntervals.h"


ArrayIntervals::ArrayIntervals(const int *_arr, int size) : arr(nullptr), size(size) {
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = _arr[i];
    }
}

ArrayIntervals::~ArrayIntervals() {
    delete[] arr;
}

void ArrayIntervals::printIntervals(int a, int b) {
    std::queue<int> smallest;
    std::queue<int> middle;
    std::queue<int> biggest;

    // Put in their queues
    for (int i = 0; i < size; i++) {
        int current = arr[i];

        if (current < a) {
            smallest.push(current);
        } else if (current <= b) {
            middle.push(current);
        } else {
            biggest.push(current);
        }
    }

    // Print accordingly
    printQueue(smallest);
    printQueue(middle);
    printQueue(biggest);
}

void ArrayIntervals::printQueue(std::queue<int> queue) {
    while (!queue.empty()) {
        std::cout << queue.front() << ", ";
        queue.pop();
    }
}