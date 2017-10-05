#include <iostream>

struct Box {
    int value;
    Box *next;

    Box(int value, Box *next) : value(value), next(next) {}

};

/**
 * 1. Count
 */

int count(Box *list, int x) {
    int c = 0;

    while (list != nullptr) {
        if (list->value == x) {
            c++;
        }
        list = list->next;
    }

    return c;
}

void testCount() {
    Box *list = new Box(11, new Box(5, new Box(11, nullptr)));

    std::cout << count(list, 11) << " = 2" << std::endl;
    std::cout << count(list, 5) << " = 1" << std::endl;
    std::cout << count(list, 9) << " = 0" << std::endl;
}

/**
 * 2. range
 */
Box *range(int x, int y) {
    Box *first = nullptr;
    for (int i = y; i >= x; i--) {
        first = new Box(i, first);
    }

    return first;
}

void testRange() {
    Box *r = range(5, 10);

    while (r != nullptr) {
        std::cout << r->value << ", ";

        r = r->next;
    }
}

/**
 * 3. Remove All
 */

void removeAll(Box *&list, int x) {
    Box *curr = list;
    Box *last = nullptr;

    while (curr != nullptr) {
        if (curr->value == x) {
            if (last != nullptr) {
                last->next = curr->next;
                delete curr;
            } else {
                Box *next = curr->next;
                curr->value = next->value;
                curr->next = next->next;
                delete next;
            }
        }
        last = curr;
        curr = curr->next;
    }
}

void testRemoveAll() {
    Box *list = new Box(11, new Box(5, new Box(11, nullptr)));

    removeAll(list, 11);

    while (list != nullptr) {
        std::cout << list->value << ", ";

        list = list->next;
    }
}

/**
 * 4. Append
 */

void append(Box *&start, Box *tail) {
    Box *iter = start;

    while (iter->next != nullptr) {
        iter = iter->next;
    }

    iter->next = tail;
}

void testAppend() {
    Box *start = new Box(1, new Box(5, new Box(42, nullptr)));
    Box *end = new Box(-1, new Box(-5, new Box(-42, nullptr)));

    append(start, end);

    while (start != nullptr) {
        std::cout << start->value << ", ";

        start = start->next;
    }
}

/**
 * 5. Concat
 */

Box *concat(Box *first, Box *second) {
    Box *copiedCurr = new Box(first->value, nullptr);
    Box *result = copiedCurr;

    first = first->next;

    while (first != nullptr) {
        copiedCurr->next = new Box(first->value, nullptr);

        copiedCurr = copiedCurr->next;
        first = first->next;
    }

    while (second != nullptr) {
        copiedCurr->next = new Box(second->value, nullptr);

        copiedCurr = copiedCurr->next;
        second = second->next;
    }


    return result;
}

void testConcat() {
    Box *start = new Box(1, new Box(5, new Box(42, nullptr)));
    Box *end = new Box(-1, new Box(-5, new Box(-42, nullptr)));

    Box *result = concat(start, end);

    while (result != nullptr) {
        std::cout << result->value << ", ";

        result = result->next;
    }
}

/**
 * 6. Map
 */

void map(Box *&list, int (*func)(int)) {
    Box *iter = list;

    while (iter != nullptr) {
        iter->value = func(iter->value);
        iter = iter->next;
    }
}

int square(int x) {
    return x * x;
}

void testMap() {
    Box *list = new Box(1, new Box(5, new Box(42, nullptr)));

    map(list, square);
    map(list, [](int x) -> int { return x + 42; });

    while (list != nullptr) {
        std::cout << list->value << ", ";

        list = list->next;
    }
}

/**
 * 7. Reverse
 */

Box *reverse(Box *list) {
    Box *reversed = nullptr;

    while (list != nullptr) {
        reversed = new Box(list->value, reversed);
        list = list->next;
    }

    return reversed;
}

void testReverse() {
    Box *orig = new Box(1, new Box(5, new Box(42, nullptr)));

    Box *reversed = reverse(orig);

    while (reversed != nullptr) {
        std::cout << reversed->value << ", ";

        reversed = reversed->next;
    }
}

/**
 * 8. Duplicates
 */

bool duplicates(Box *list) {
    while (list != nullptr) {
        Box *iter = list->next;
        while (iter != nullptr) {
            if (iter->value == list->value) {
                return true;
            }

            iter = iter->next;
        }

        list = list->next;
    }


    return false;
}

void testDuplicates() {
    Box *unique = new Box(1, new Box(5, new Box(42, nullptr)));
    Box *dupl = new Box(11, new Box(5, new Box(11, nullptr)));

    std::cout << duplicates(unique) << " = false" << std::endl;
    std::cout << duplicates(dupl) << " = true" << std::endl;
}

/**
 * 9. Remove Duplicates
 */

void removeDuplicates(Box *&list) {
    Box *orig = list;
    while (orig != nullptr) {
        Box *current = orig->next;
        Box *last = orig;

        while (current != nullptr) {
            if (current->value == orig->value) {
                last->next = current->next;
                delete current;
            }

            last = current;
            current = current->next;
        }

        orig = orig->next;
    }
}

void testRemoveDupl() {
    Box *dupl = new Box(11, new Box(5, new Box(11, nullptr)));

    removeDuplicates(dupl);

    while (dupl != nullptr) {
        std::cout << dupl->value << ", ";

        dupl = dupl->next;
    }
}

/**
 * 10. Is Sorted?
 */

bool isSorted(Box *list) {
    bool isAsc;
    int last = NULL;
    Box *iter = list;

    while(iter != nullptr) {
        if(last == NULL) {
            isAsc = iter->value < iter->next->value;
        } else if(iter->value < last) {
            if(isAsc) {
                return false;
            }
        } else if(iter->value > last) {
            if(!isAsc) {
                return false;
            }
        }

        last = iter->value;
        iter = iter->next;
    }

    return true;
}

void testIsSorted() {
    Box *asc = new Box(1, new Box(5, new Box(42, nullptr)));
    Box *desc = new Box(33, new Box(22, new Box(11, nullptr)));
    Box *no = new Box(3, new Box(22, new Box(11, nullptr)));

    std::cout << isSorted(asc) << " = true" << std::endl;
    std::cout << isSorted(desc) << " = true" << std::endl;
    std::cout << isSorted(no) << " = false" << std::endl;
}

/**
 * 11. Palindrome
 */

bool palindrome(Box *list) {
    Box *reversed = reverse(list);

    while(list != nullptr) {
        if(list->value != reversed->value) {
            return false;
        }

        list = list->next;
        reversed = reversed->next;
    }

    return true;
}

void testPalindrome() {
    Box *yes = new Box(33, new Box(22, new Box(11, new Box(22, new Box(33, nullptr)))));
    Box *no = new Box(3, new Box(22, new Box(11, nullptr)));


    std::cout << palindrome(yes) << " = true" << std::endl;
    std::cout << palindrome(no) << " = false" << std::endl;
}

int main() {
//    testCount();
//    testRange();
//    testRemoveAll();
//    testAppend();
//    testConcat();
//    testMap();
//    testReverse();
//    testDuplicates();
//    testRemoveDupl();
//    testIsSorted();
    testPalindrome();
    return 0;
}