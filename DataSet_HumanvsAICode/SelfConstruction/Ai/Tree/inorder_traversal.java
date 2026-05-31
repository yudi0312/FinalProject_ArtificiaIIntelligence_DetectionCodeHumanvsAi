public class InorderTraversal {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Executes an Inorder Traversal print sequence.
     */
    public void traverseInorder(Node node) {
        if (node == null) return;

        traverseInorder(node.left);            // Process Left
        System.out.print(node.data + " ");     // Process Root Value
        traverseInorder(node.right);           // Process Right
    }

    public static void main(String[] args) {
        InorderTraversal tree = new InorderTraversal();
        Node root = new Node(40);
        root.left = new Node(20);
        root.right = new Node(60);

        System.out.print("Inorder Sequence: ");
        tree.traverseInorder(root); // Expected: 20 40 60
        System.out.println();
    }
}