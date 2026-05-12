#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
using namespace std;

void linkedListMenu() {
    LinkedList list;
    int choice, val;
    do {
        cout << "\n--- Linked List ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n0. Back\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; list.insert(val); break;
            case 2: cout << "Value: "; cin >> val; list.remove(val); break;
            case 3: cout << "Value: "; cin >> val;
                    cout << (list.search(val) ? "Found!\n" : "Not found.\n"); break;
            case 4: list.display(); break;
        }
    } while (choice != 0);
}

void stackMenu() {
    Stack s;
    int choice, val;
    do {
        cout << "\n--- Stack ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Back\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; s.push(val); break;
            case 2: cout << "Popped: " << s.pop() << "\n"; break;
            case 3: cout << "Top: " << s.peek() << "\n"; break;
            case 4: s.display(); break;
        }
    } while (choice != 0);
}

void queueMenu() {
    Queue q;
    int choice, val;
    do {
        cout << "\n--- Queue ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek Front\n4. Display\n0. Back\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; q.enqueue(val); break;
            case 2: cout << "Dequeued: " << q.dequeue() << "\n"; break;
            case 3: cout << "Front: " << q.peekFront() << "\n"; break;
            case 4: q.display(); break;
        }
    } while (choice != 0);
}

void bstMenu() {
    BST tree;
    int choice, val;
    do {
        cout << "\n--- Binary Search Tree ---\n";
        cout << "1. Insert\n2. Search\n3. Display (Inorder)\n0. Back\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; tree.insert(val); break;
            case 2: cout << "Value: "; cin >> val;
                    cout << (tree.search(val) ? "Found!\n" : "Not found.\n"); break;
            case 3: tree.display(); break;
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        cout << "\n=== Data Structures Visualizer ===\n";
        cout << "1. Linked List\n2. Stack\n3. Queue\n4. Binary Search Tree\n0. Exit\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: linkedListMenu(); break;
            case 2: stackMenu(); break;
            case 3: queueMenu(); break;
            case 4: bstMenu(); break;
        }
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
