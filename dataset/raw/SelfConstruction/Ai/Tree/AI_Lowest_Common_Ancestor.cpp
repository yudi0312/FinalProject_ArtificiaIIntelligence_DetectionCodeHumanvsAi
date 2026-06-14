#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* findLCA(Node* root, int a, int b) {
    if (!root) return nullptr;

    if (a < root->data && b < root->data)
        return findLCA(root->left, a, b);

    if (a > root->data && b > root->data)
        return findLCA(root->right, a, b);

    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);

    cout << findLCA(root, 10, 30)->data;

    return 0;
}