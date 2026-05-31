void mirror(Node* node) {
        // code here
        if(node == NULL){
            return;
        }
        Node* left = node->left;
        node->left = node->right;
        node->right = left;
        mirror(node->left);
        mirror(node->right);
    }
