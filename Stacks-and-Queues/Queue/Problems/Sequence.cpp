//
// Created by vladimir on 06/11/17.
//

#include "Sequence.h"


Sequence::Sequence(int initial): index(1) {
    sequence.push(initial);
}

int Sequence::getElement(int i) {
    // Generate all
    while(index < i) {
        generate(i);
    }

    // Empty queue and leave only last element
    while(sequence.size() > 1) {
        sequence.pop();
    }

    // The last element is the i-th
    return sequence.front();
}

void Sequence::generate(int maxIndex) {
    int first = sequence.front();
    sequence.pop();

    push(first + 1);

    if(index == maxIndex) {
        return;
    }

    push(first * 2);
}

void Sequence::push(int elem) {
    sequence.push(elem);
    index++;
}
