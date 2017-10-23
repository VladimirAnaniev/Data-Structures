#include <iostream>
#include "Stack/Algorithms/towerOfHanoi.cpp"
#include "Queue/PriorityQueue.h"


int main() {
//    testTowerOfHanoi(20);

    PriorityQueue pq;

    pq.enqueue(22);
    pq.enqueue(10);
    pq.enqueue(-1);
    pq.enqueue(15);

    std::cout<<pq.dequeue()<<", ";
    std::cout<<pq.dequeue()<<", ";

    pq.enqueue(100);
    pq.enqueue(23);

    while(!pq.isEmpty()) {
        std::cout<<pq.dequeue()<<", ";
    }
    return 0;
}