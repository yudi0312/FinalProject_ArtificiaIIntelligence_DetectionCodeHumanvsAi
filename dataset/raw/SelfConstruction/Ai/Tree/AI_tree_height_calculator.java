public class TreeHeight {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Recursive function to compute tree height.
     * Time Complexity: O(n)
     */
    public int calculateHeight(Node node) {
        if (node == null) {
            return 0; // Base case: height of an empty tree branch is 0
        }

        // Recursively find the height of left and right subtrees
        int leftHeight = calculateHeight(node.left);
        int rightHeight = calculateHeight(node.right);

        // Height is the maximum depth encountered plus 1 (for the current node)
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static void main(String[] args) {
        TreeHeight tree = new TreeHeight();
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(15);
        root.left.left = new Node(2); // Deepest node

        System.out.println("Maximum Tree Height: " + tree.calculateHeight(root)); // Expected: 3
    }
}