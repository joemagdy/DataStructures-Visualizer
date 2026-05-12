#pragma once
#include <iostream>
using namespace std;

struct BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
    BSTNode* root = nullptr;

    // Private helpers (recursive)
    BSTNode* insert(BSTNode* node, int v) {
        if (!node) return new BSTNode(v);
        if (v < node->val)      node->left  = insert(node->left, v);
        else if (v > node->val) node->right = insert(node->right, v);
        else cout << v << " already exists.\n";
        return node;
    }

    bool search(BSTNode* node, int v) {
        if (!node) return false;
        if (node->val == v) return true;
        return v < node->val ? search(node->left, v) : search(node->right, v);
    }

    // Left -> Root -> Right
    void inorder(BSTNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void destroy(BSTNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~BST() { destroy(root); }

    void insert(int v) {
        root = insert(root, v);
        cout << v << " inserted into BST.\n";
    }

    bool search(int v) { return search(root, v); }

    // Print sorted order
    void display() {
        if (!root) { cout << "[ Empty BST ]\n"; return; }
        cout << "Inorder (sorted): ";
        inorder(root);
        cout << "\n";
    }
};
