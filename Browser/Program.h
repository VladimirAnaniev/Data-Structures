//
// Created by vananiev on 12/24/17.
//

#ifndef BROWSER_PROGRAM_H
#define BROWSER_PROGRAM_H


#include "Console.h"
#include "Browser.h"

class Program {
    bool running = false;
    Browser browser;

public:
    Program() : browser() {}

    void run() {
        running = true;

        while (running) {
            String command = Console::read();
            dispatch(command);
        }
    }

    void dispatch(const String &command) {
        List<String> parts = command.trim().split();

        String action = parts[0];
        if (action == String("GO")) {
            browser.go(parts[1]);
        } else if (action == String("INSERT")) {
            browser.insert(parts[1]);
        } else if (action == String("BACK")) {
            browser.back();
        } else if (action == String("FORWARD")) {
            browser.forward();
        } else if (action == String("REMOVE")) {
            browser.remove();
        } else if (action == String("PRINT")) {
            browser.print();
        } else if (action == String("SORT")) {
            browser.sort(parts[1]);
        } else if (action == String("QUIT")) {
            quit();
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    void quit() {
        this->running = false;
    }
};


#endif //BROWSER_PROGRAM_H
