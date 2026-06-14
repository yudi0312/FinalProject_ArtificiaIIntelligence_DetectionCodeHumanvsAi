public class TreeInsertion {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Inserts a value recursively at its correct location in a BST.
     */
    public Node insert(Node node, int data) {
        // If an open space is found, create the node and return it
        if (node == null) {
            return new Node(data);
        }

        // Otherwise, traverse down the appropriate branch
        if (data < node.data) {
            node.left = insert(node.left, data);
        } else if (data > node.data) {
            node.right = insert(node.right, data);
        }

        return node; // Return original unchanged node pointer
    }

    public void printInorder(Node node) {
        if (node == null) return;
        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void main(String[] args) {
        TreeInsertion bst = new TreeInsertion();
        Node root = null;

        // Inserting elements one after another
        root = bst.insert(root, 100);
        root = bst.insert(root, 50);
        root = bst.insert(root, 150);
        root = bst.insert(root, 25);

        System.out.print("BST Elements after insertions (Sorted view): ");
        bst.printInorder(root); // Expected: 25 50 100 150
        System.out.println();
    }
}