//
// Created by vananiev on 12/24/17.
//

#ifndef BROWSER_CONSOLE_H
#define BROWSER_CONSOLE_H

#include "../String/String.h"

class Console {
public:
    static String read() {
        char input[128];
        std::cin.getline(input, 128);
        String str = input;

        return str;
    }

    static void print(String str) {
        std::cout << str << std::endl;
    }
};


#endif //BROWSER_CONSOLE_H
