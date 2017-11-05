//
// Created by vladimir on 05/11/17.
//

#ifndef STACKS_AND_QUEUES_DECOMPRESSOR_H
#define STACKS_AND_QUEUES_DECOMPRESSOR_H

#include <string>


class Decompressor {
    static bool isNumber(char c);

    static bool isLetter(char c);

public:

    static std::string decompress(std::string compressed);

    static bool test();

};


#endif //STACKS_AND_QUEUES_DECOMPRESSOR_H
