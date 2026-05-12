#pragma once
#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int v) : data(v), next(nullptr) {}
};

class Queue {
    QNode* front;
    QNode* back;

public:
    Queue() : front(nullptr), back(nullptr) {}

    ~Queue() {
        while (front) {
            QNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Add to back
    void enqueue(int val) {
        QNode* n = new QNode(val);
        if (!back) { front = back = n; }
        else { back->next = n; back = n; }
        cout << val << " enqueued.\n";
    }

    // Remove from front
    int dequeue() {
        if (!front) { cout << "Queue is empty!\n"; return -1; }
        int val = front->data;
        QNode* temp = front;
        front = front->next;
        if (!front) back = nullptr;
        delete temp;
        cout << val << " dequeued.\n";
        return val;
    }

    // See front without removing
    int peekFront() {
        if (!front) { cout << "Queue is empty!\n"; return -1; }
        return front->data;
    }

    // Print queue visually
    void display() {
        if (!front) { cout << "[ Empty Queue ]\n"; return; }
        cout << "FRONT -> ";
        QNode* curr = front;
        while (curr) {
            cout << "[ " << curr->data << " ]";
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << " <- BACK\n";
    }
};
