//
// Created by vladimir on 05/11/17.
//

#include <iostream>
#include <stack>
#include "Decompressor.h"


std::string Decompressor::decompress(std::string compressed) {
    std::stack<std::string> substrings;
    substrings.push("");

    std::stack<int> counts;

    std::string temp;
    for(int i = 0; i < compressed.size(); i++) {
        char c = compressed[i];

        if (isLetter(c)) {
            temp += c;
        } else {
            if (temp.size()) {
                substrings.push(temp);
                temp.clear();
            }

            if (isNumber(c)) {
                counts.push(c - '0');
                i++; //Skip opening bracket
            } else if (c == ')') {
                int n = counts.top();
                counts.pop();

                std::string toRepeat = substrings.top();
                substrings.pop();

                std::string begin = substrings.top();
                substrings.pop();

                for (int j = 0; j < n; j++) {
                    begin += toRepeat;
                }

                substrings.push(begin);
            }
        }
    }

    if(substrings.top().size() == 0) {
        return temp;
    }

    return substrings.top();

}

bool Decompressor::test() {
    std::cout << "A -> " << decompress("A") << std::endl;
    std::cout << "AB -> " << decompress("AB") << std::endl;
    std::cout << "3(A) -> " << decompress("3(A)") << std::endl;
    std::cout << "3(AB2(C)) -> " << decompress("3(AB2(C))") << std::endl;
    std::cout << "9(ZQ) -> " << decompress("9(ZQ)") << std::endl;
}

bool Decompressor::isNumber(char c) {
    int num = c - '0';
    return num >= 0 && num <= 9;
}

bool Decompressor::isLetter(char c) {
    bool isUppercase = c - 'A' >= 0 && c - 'A' <= 25;
    bool isLowercase = c - 'a' >= 0 && c - 'a' <= 25;

    return isUppercase || isLowercase;
}