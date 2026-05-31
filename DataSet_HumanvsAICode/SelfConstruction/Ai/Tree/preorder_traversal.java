public class PreorderTraversal {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Executes a Preorder Traversal print sequence.
     */
    public void traversePreorder(Node node) {
        if (node == null) return;

        System.out.print(node.data + " ");     // Process Root Value immediately
        traversePreorder(node.left);           // Process Left
        traversePreorder(node.right);          // Process Right
    }

    public static void main(String[] args) {
        PreorderTraversal tree = new PreorderTraversal();
        Node root = new Node(40);
        root.left = new Node(20);
        root.right = new Node(60);

        System.out.print("Preorder Sequence: ");
        tree.traversePreorder(root); // Expected: 40 20 60
        System.out.println();
    }
}