#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void serialize(Node* root, stringstream& output) {
    if (!root) {
        output << "# ";
        return;
    }

    output << root->data << " ";

    serialize(root->left, output);
    serialize(root->right, output);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    stringstream serializedTree;

    serialize(root, serializedTree);

    cout << serializedTree.str();

    return 0;
}