//
// Created by vladimir on 05/11/17.
//

#ifndef STACKS_AND_QUEUES_DECOMPRESSOR_H
#define STACKS_AND_QUEUES_DECOMPRESSOR_H

#include <string>

/**
 * Напишете програма, която при получен "компресиран" низ на стандартния вход, извежда на стандартния
 * изход декомпресираната му версия.
 * Компресираният низ съдържа 2 вида конструкции:
 * - букви, които са символ от 'A' до 'Z' и се декомпресират до същата буква;
 * - групи, които започват с число, последвано от компресиран низ в скоби. Декомпресират се като се
 * декомпресира низа в скобите и се повтори толкова пъти, колкото е числото.
 *
 * Примери:
 * A -> A
 * AB -> AB
 * 3(A) -> AAA
 * 3(AB2(B)) -> ABBBABBBABBB
 * 12(ZQ) -> ZQZQZQZQZQZQZQZQZQZQZQZQ
 */


class Decompressor {
    static bool isNumber(char c);

    static bool isLetter(char c);

public:

    static std::string decompress(std::string compressed);

    static bool test();

};


#endif //STACKS_AND_QUEUES_DECOMPRESSOR_H
