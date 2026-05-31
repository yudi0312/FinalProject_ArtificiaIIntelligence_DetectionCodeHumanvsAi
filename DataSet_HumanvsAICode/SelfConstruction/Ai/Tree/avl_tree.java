public class AVLTreeStructure {
    static class Node {
        int data, height;
        Node left, right;

        public Node(int data) {
            this.data = data;
            this.height = 1; // New nodes start with a height of 1
        }
    }

    private Node root;

    // Utility to get height safely
    private int height(Node node) {
        return (node == null) ? 0 : node.height;
    }

    // Utility to calculate balance factor
    private int getBalance(Node node) {
        return (node == null) ? 0 : height(node.left) - height(node.right);
    }

    // Right rotation mechanism for Left-Left imbalances
    private Node rightRotate(Node y) {
        Node x = y.left;
        Node t2 = x.right;

        x.right = y;
        y.left = t2;

        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1;

        return x;
    }

    public static void main(String[] args) {
        AVLTreeStructure avl = new AVLTreeStructure();
        avl.root = new Node(30);
        avl.root.left = new Node(20);
        avl.root.left.left = new Node(10);

        // Fixing a left-heavy state immediately via right rotation
        avl.root = avl.rightRotate(avl.root);
        System.out.println("AVL Right Rotation executed. New balanced root: " + avl.root.data);
    }
}