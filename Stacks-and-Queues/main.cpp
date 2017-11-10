#include <iostream>
#include "Stack/Problems/Decompressor.h"
#include "Queue/Problems/Sequence.h"
#include "Queue/Problems/ArrayIntervals.h"
#include "Queue/Problems/Labyrinth.h"


int main() {
    char** maze = new char*[3];
    maze[0] = new char[4] {'0', '0', 'x', 0};
    maze[1] = new char[4] {'x', '0', '*', 0};
    maze[2] = new char[4] {'0', 'x', '0', 0};
    Labyrinth labyrinth(maze, 3);
    labyrinth.fillLengths();
    labyrinth.print();
    return 0;
}