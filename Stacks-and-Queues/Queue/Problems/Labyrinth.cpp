//
// Created by vladimir on 06/11/17.
//

#include <iostream>
#include <cstring>
#include <queue>
#include "Labyrinth.h"


Labyrinth::Labyrinth(char **_maze, int n) : maze(nullptr), n(n) {
    maze = new char *[n];

    for (int i = 0; i < n; i++) {
        auto *row = new char[strlen(_maze[i]) + 1];
        strcpy(row, _maze[i]);
        maze[i] = row;
    }
}

Labyrinth::~Labyrinth() {
    for (int i = 0; i < n; i++) {
        delete[] maze[i];
    }

    delete[] maze;
}

void Labyrinth::print() {
    for (int i = 0; i < n; i++) {
        std::cout << maze[i] << std::endl;
    }
}

void Labyrinth::fillLengths() {
    std::queue<PositionLength> positions;
    positions.push(PositionLength {getStartingPoint(), 0});

    while(!positions.empty()) {
        PositionLength current = positions.front();
        positions.pop();

        for(int i = -1; i <= 1; i += 2) {
            // verticals
            Position vertical {current.pos.r + i, current.pos.c};
            if(isEmpty(vertical)) {
                PositionLength vertLen {vertical, current.length + 1};
                fill(vertLen);
                positions.push(vertLen);
            }

            //horizontals
            Position horizontal {current.pos.r, current.pos.c + i};
            if(isEmpty(horizontal)) {
                PositionLength horLen {horizontal, current.length + 1};
                fill(horLen);
                positions.push(horLen);
            }
        }
    }

    // All reachable have been filled
    fillUnreachable();
}

Position Labyrinth::getStartingPoint() {
    for(int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if(maze[r][c] == '*') {
                return Position {r, c};
            }
        }
    }
}

bool Labyrinth::isEmpty(Position pos) {
    return pos.r >= 0 && pos.r < n && pos.c >= 0 && pos.c < n && maze[pos.r][pos.c] == '0';
}

void Labyrinth::fill(PositionLength posLen) {
    maze[posLen.pos.r][posLen.pos.c] = '0' + posLen.length;
}

void Labyrinth::fillUnreachable() {
    for(int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if(maze[r][c] == '0') {
                maze[r][c] = 'u';
            }
        }
    }
}