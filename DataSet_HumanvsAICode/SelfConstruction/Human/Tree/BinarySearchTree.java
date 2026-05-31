public class BinarySearchTree {

    // Root of BST
    BstNode root;

    BinarySearchTree() {
        root = null;
    }

    void Insert(int data) {
        root = Insert(root, data);
    }

    BstNode Insert(BstNode root, int data) {

        if (root == null) {
            root = new BstNode(data);
        } else if (data < root.data)
            root.Left = Insert(root.Left, data);
        else if (data > root.data)
            root.Right = Insert(root.Right, data);

        return root;
    }

    void InOrder() {
        InOrder(root);
    }

    void InOrder(BstNode root) {
        if (root != null) {
            InOrder(root.Left);
            System.out.print(root.data + " ");
            InOrder(root.Right);
        }
    }

    void PreOrder() {
        PreOrder(root);
    }

    void PreOrder(BstNode root) {
        if (root == null)
            return;
        System.out.print(root.data + " ");
        PreOrder(root.Left);
        PreOrder(root.Right);
    }

    void PostOrder() {
        PostOrder(root);
    }

    void PostOrder(BstNode root) {
        if (root == null)
            return;
        PostOrder(root.Left);
        PostOrder(root.Right);
        System.out.print(root.data + " ");
    }

    int Height() {
        return Height(root);
    }

    int Height(BstNode root) {
        if (root == null)
            return -1;
        return Math.max(Height(root.Left), Height(root.Right)) + 1;
    }

    boolean Search(int data) {
        return Search(root, data);
    }

    boolean Search(BstNode root, int data) {
        boolean result;
        if (root == null) {
            result = false;
        } else if (root.data == data) {
            result = true;
        } else if (data <= root.data) {
            result = Search(root.Left, data);
        } else {
            result = Search(root.Right, data);
        }
        return result;
    }

    void Delete(int data) {
        Delete(root, data);
    }

    BstNode Delete(BstNode root, int data) {
        if (root == null)
            return root;
        else if (data < root.data)
            root.Left = Delete(root.Left, data);
        else if (data > root.data)
            root.Right = Delete(root.Right, data);
        else // found
        {
            // Case 1: No child
            if (root.Left == null && root.Right == null) {
                // delete root;
                root = null;
            }
            // Case 2: One child
            else if (root.Left == null) {
                root = root.Right;
            } else if (root.Right == null) {
                root = root.Left;
            }
            // Case 3: 2 children
            else {
                BstNode temp = FindMin(root.Right);
                root.data = temp.data;
                root.Right = Delete(root.Right, temp.data);
            }
        }
        return root;
    }

    BstNode FindMin(BstNode root) {
        while (root.Left != null)
            root = root.Left;
        return root;
    }
}