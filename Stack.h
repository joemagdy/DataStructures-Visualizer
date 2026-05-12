#pragma once
#include <iostream>
using namespace std;

class Stack {
    int arr[100];   // storage
    int top = -1;   // -1 means empty

public:
    // Add to top
    void push(int val) {
        if (top >= 99) { cout << "Stack overflow!\n"; return; }
        arr[++top] = val;
        cout << val << " pushed to stack.\n";
    }

    // Remove from top
    int pop() {
        if (top == -1) { cout << "Stack is empty!\n"; return -1; }
        int val = arr[top--];
        cout << val << " popped.\n";
        return val;
    }

    // See top without removing
    int peek() {
        if (top == -1) { cout << "Stack is empty!\n"; return -1; }
        return arr[top];
    }

    bool isEmpty() { return top == -1; }

    // Print stack visually (top to bottom)
    void display() {
        if (top == -1) { cout << "[ Empty Stack ]\n"; return; }
        for (int i = top; i >= 0; i--) {
            if (i == top) cout << "TOP -> ";
            else          cout << "       ";
            cout << "[ " << arr[i] << " ]\n";
        }
        cout << "       -------\n";
    }
};
