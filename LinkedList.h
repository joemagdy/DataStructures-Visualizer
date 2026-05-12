#pragma once
#include <iostream>
using namespace std;

// Each box in the chain
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Destructor — free all memory
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // Add to the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
        cout << val << " inserted.\n";
    }

    // Delete by value
    void remove(int val) {
        if (!head) { cout << "List is empty!\n"; return; }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << val << " deleted.\n";
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;
        if (!curr->next) { cout << "Value not found!\n"; return; }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << val << " deleted.\n";
    }

    // Search by value
    bool search(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    // Print the list visually
    void display() {
        if (!head) { cout << "[ Empty List ]\n"; return; }
        Node* curr = head;
        while (curr) {
            cout << "[" << curr->data << "]";
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << " -> NULL\n";
    }
};
