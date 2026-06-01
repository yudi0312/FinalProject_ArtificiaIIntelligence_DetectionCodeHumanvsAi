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

int countNodes(Node* root) {
    if (!root)
        return 0;

    return 1 +
           countNodes(root->left) +
           countNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Total Nodes: "
         << countNodes(root);

    return 0;
}