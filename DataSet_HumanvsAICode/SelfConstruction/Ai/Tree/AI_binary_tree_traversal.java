public class GeneralBinaryTree {
    // Independent node definition for a standard binary tree
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private Node root;

    public static void main(String[] args) {
        GeneralBinaryTree tree = new GeneralBinaryTree();
        
        // Constructing a standard binary tree manually
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);

        System.out.println("Binary Tree initialized successfully. Root node value: " + tree.root.data);
    }
}