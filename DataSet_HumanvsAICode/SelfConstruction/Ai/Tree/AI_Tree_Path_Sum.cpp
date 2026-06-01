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

bool hasPathSum(Node* root, int target) {
    if (!root)
        return false;

    if (!root->left && !root->right)
        return target == root->data;

    return hasPathSum(root->left, target - root->data) ||
           hasPathSum(root->right, target - root->data);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);

    cout << (hasPathSum(root, 9) ? "Yes" : "No");

    return 0;
}