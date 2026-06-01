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

void mirror(Node* root) {
    if (!root) return;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    mirror(root);

    inorder(root);

    return 0;
}