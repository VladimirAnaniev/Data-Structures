//
// Created by vladimir on 06/11/17.
//

#ifndef STACKS_AND_QUEUES_LABYRINTH_H
#define STACKS_AND_QUEUES_LABYRINTH_H

/*
 * Даден е лабиринт с размери n x n. Някои от клетките на лабиринта са празни (0), а други са запълнени (х).
 * Можете да се движите от празна клетка до друга празна клетка, ако двете имат обща стена. При дадена
 * начална позиция (*), изчислете и попълнете лабиринта с минималната дължина от началната позиция до
 * всяка друга. Ако някоя клетка не може да бъде достигната, я попълнете с "u”.
 */

struct Position {
    int r;
    int c;
};

struct PositionLength {
    Position pos;
    int length;
};

class Labyrinth {
    char **maze;
    int n;



    Position getStartingPoint();

    bool isEmpty(Position pos);

    void fill(PositionLength posLen);

    void fillUnreachable();

public:
    Labyrinth(char **maze, int n);
    ~Labyrinth();
    //TODO: BIG 4;

    void fillLengths();

    void print();
};


#endif //STACKS_AND_QUEUES_LABYRINTH_H
