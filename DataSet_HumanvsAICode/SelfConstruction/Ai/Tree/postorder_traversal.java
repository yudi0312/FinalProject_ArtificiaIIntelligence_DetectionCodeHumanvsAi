public class PostorderTraversal {
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    /**
     * Executes a Postorder Traversal print sequence.
     */
    public void traversePostorder(Node node) {
        if (node == null) return;

        traversePostorder(node.left);          // Process Left
        traversePostorder(node.right);         // Process Right
        System.out.print(node.data + " ");     // Process Root Value last
    }

    public static void main(String[] args) {
        PostorderTraversal tree = new PostorderTraversal();
        Node root = new Node(40);
        root.left = new Node(20);
        root.right = new Node(60);

        System.out.print("Postorder Sequence: ");
        tree.traversePostorder(root); // Expected: 20 60 40
        System.out.println();
    }
}