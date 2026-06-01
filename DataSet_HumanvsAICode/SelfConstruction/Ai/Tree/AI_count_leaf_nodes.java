public class CountLeafNodes {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Counts leaf nodes recursively.
     */
    public int getLeafCount(Node node) {
        if (node == null) {
            return 0;
        }
        // If a node has no children, it is a leaf
        if (node.left == null && node.right == null) {
            return 1;
        }
        // Sum leaves from both left and right directions
        return getLeafCount(node.left) + getLeafCount(node.right);
    }

    public static void main(String[] args) {
        CountLeafNodes tree = new CountLeafNodes();
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);  // Leaf 1
        root.left.right = new Node(5); // Leaf 2

        System.out.println("Total Leaf Nodes: " + tree.getLeafCount(root)); // Expected: 3 (Nodes 4, 5, and 3)
    }
}