//
// Created by vananiev on 12/24/17.
//

#ifndef BROWSER_TAB_H
#define BROWSER_TAB_H

#include <ctime>
#include "../String/String.h"

class Tab {
    String url;
    time_t timestamp;

public:
    void go(const String &url) {
        this->url = url;
        timestamp = std::time(nullptr);
    }

    String print() {
        return "> " + url + " " + timestamp;
    }
};


#endif //BROWSER_TAB_H
