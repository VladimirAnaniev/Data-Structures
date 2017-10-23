//
// Created by vladimir on 23/10/17.
//

#ifndef STACKS_AND_QUEUES_PRIORITYQUEUE_H
#define STACKS_AND_QUEUES_PRIORITYQUEUE_H

#include "LinkedQueue.h"

class PriorityQueue : public Queue<int> {
    bool isSorted = false;
    LinkedNode<int> *head = nullptr;

    void sort() {
        mergeSort(head);
        isSorted = true;
    }

    void mergeSort(LinkedNode<int> *&node) {
        if (node == nullptr || node->next == nullptr) {
            return;
        }

        LinkedNode<int> *left = nullptr;
        LinkedNode<int> *right = nullptr;

        split(node, left, right);

        mergeSort(left);
        mergeSort(right);

        node = merge(left, right);
    }

    void split(LinkedNode<int> *source, LinkedNode<int> *&left, LinkedNode<int> *&right) {
        if(source == nullptr || source->next == nullptr) {
            left = source;
            return;
        }

        LinkedNode<int> *slow = source;
        LinkedNode<int> *fast = source->next;

        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        left = source;
        right = slow->next;
        slow->next = nullptr;
    }

    LinkedNode<int> *merge(LinkedNode<int> *left, LinkedNode<int> *right) {
        if(left == nullptr) {
            return right;
        }

        if(right == nullptr) {
            return left;
        }

        LinkedNode<int> *sorted = nullptr;

        if(left->data < right->data) {
            sorted = left;
            sorted->next = merge(left->next, right);
        } else {
            sorted = right;
            sorted->next = merge(left, right->next);
        }

        return sorted;
    }

public:

    void enqueue(const int &data) override {
        if (!isEmpty()) {
            isSorted = false;
        }

        auto *newElem = new LinkedNode<int>();
        newElem->data = data;
        newElem->next = head;

        head = newElem;
    }

    bool isEmpty() const override {
        return head == nullptr;
    }

    int dequeue() override {
        if (!isSorted) {
            sort();
        }

        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        LinkedNode<int> *removed = head;
        head = head->next;

        int data = removed->data;
        delete removed;

        return data;
    }

    const int &peek() override {
        if(!isSorted) {
            sort();
        }

        if(isEmpty()) {
            throw std::logic_error("Queue is empty");
        }

        return head->data;
    }
};

#endif //STACKS_AND_QUEUES_PRIORITYQUEUE_H
