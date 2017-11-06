#include <iostream>
#include "Stack/Problems/Decompressor.h"
#include "Queue/Problems/Sequence.h"
#include "Queue/Problems/ArrayIntervals.h"


int main() {
    ArrayIntervals intervals(new int[5] {10, 5, 3,0,800}, 5);
    intervals.printIntervals(5, 22);
    return 0;
}